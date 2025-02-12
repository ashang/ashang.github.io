---
title: "Make Clicking in Scroll Gutter in VSCode Move By Page"
layout: post
---

VS Code seems to work much better than I think anyone would have expected.  I
am trying to switch to it as my editor--any such transition involves some pain.

One of the first things that bothered me was that if you click in the "gutter"
region of scroll bars in VS code (the part that is not the "slider"), it jumps
to an absolute position in the file corresponding to where you click.  That is
not how scroll bars work in any other program I have seen.

Usually the logic is:

* If you click in the area above the slider, it jumps up by a page.
* If you click in the area below the slider, it jumps down by a page.

Plus, VS Code has a miniaturized rendered preview of the syntax-colored code
in your file running alongside the scrollbar.  That seems to make a very large
click-target if you wanted to have the absolute-position click behavior.

I assumed there would be a setting somewhere to change this.  There is not, but
there is [a GitHub issue][1] (a few, actually) of people asking for it.
Someone there at the end of the thread says:

> *"Seems an inherent issue with open source software ... Everyone wants it but
> no-one wants to fix it for free. I don't want to take the task, either. So
> ... anyone else..?*

[1]: https://github.com/Microsoft/vscode/issues/43564

Well the coronavirus has me inside with a computer not doing much.  Why not
look to see?


## Finding The Scroll Bar Implementation

Drilling into the VS Code source, I immediately beelined down through the
directory structure to something that looked promising:

[/src/vs/editor/browser/viewParts/editorScrollbar/editorScrollbar.ts][2]

[2]: https://github.com/microsoft/vscode/blob/master/src/vs/editor/browser/viewParts/editorScrollbar/editorScrollbar.ts

It's a pretty short file, though.  It reads out some options from the settings
and delegates most of its behavior to `SmoothScrollableElement`, which in turn
`extends AbstractScrollableElement`.  These live in implementation files that
are in another directory:

[src/vs/base/browser/ui/scrollbar][3]

[3]: https://github.com/microsoft/vscode/tree/master/src/vs/base/browser/ui/scrollbar

But for starters, it's probably best to see if debugging can work at all.
So I just set a breakpoint in `EditorScrollbar`s constructor and hope for
the best.


## Debugging Actually Worked!  (mostly...)

The description for how a debugger will run for a process is in a file called
`launch.json` that lives in a `.vscode` directory in your project.  It is
lucky that VS Code is configured to work for debugging itself, and comes with
such a file already.  So when you say `Run > Start Debugging` it knows how
to do all the mumbo jumbo to connect to the embedded electron browser.

There's one hitch: around when it shows the window for the VSCode being run,
the debugger pops up a message saying:

> *"Error processing attach: Error: Could not connect to debug target at
> `http://localhost:5870`: Promise was canceled"*

![Error Message](https://ae1020.github.io/assets/images/vscode-debug-error.png)

(Maybe it's just a timeout?  My laptop is nothing special, and it takes a good
solid minute for the process to start.)

But I just hit Cancel and pretend it didn't happen.  And my breakpoint in
the EditorScrollbar constructor is hit!


## Catching Scrolling in the Act

Rather than read over all the code, I figured the easiest thing to do would be
to set a breakpoint in something that changed the scroll position.  It seemed
[`SmoothScrollableElement.setScrollPosition()`][4] was a good candidate:

    public setScrollPosition(update: INewScrollPosition): void {
        this._scrollable.setScrollPositionNow(update);  // <-- breakpoint here
    }

[4]: https://github.com/microsoft/vscode/blob/494c209353f559eec7a170a1656096d606ee37e8/src/vs/base/browser/ui/scrollbar/scrollableElement.ts#L549

Theoretically, I could just click around in the scroll bar.  When the break
happened, I could look at the stack above the breakpoint to see how the
decision about the position was made.

But... no dice.  Dragging or clicking around in the scroll bar area did not
trigger it.  Maybe this was too high level, and I'd have better luck setting
the breakpoint on the [setScrollPositionNow() method of `_scrollable`][5]?

    public setScrollPositionNow(update: INewScrollPosition): void {
        // no smooth scrolling requested
        const newState = this._state.withScrollPosition(update);  // breakpoint

[5]: https://github.com/microsoft/vscode/blob/e55f6c99ccb126137375cb1636a581d7678b85c3/src/vs/base/common/scrollable.ts#L272

**That hit a breakpoint.**  So now I could see a stack, that looked like:

    Scrollable.setScrollPositionNow(update: INewScrollPosition)
    AbstractScrollBar._setDesiredScrollPositionNow(_desiredScrollPosition: number)
    AbstractScrollBar._onMouseDown(e: IMouseEvent)
    AbstractScrollBar._domNodeMouseDown(e: IMouseEvent)

Peering around the stack shows the logic is in that `_onMouseDown`, which is
calling [`ScrollBarState.getDesiredScrollPositionFromOffset()`][6].  This only
seems to be called when you click in the gutter, while clicking on the slider
invokes [`ScrollBarState.getDesiredScrollPositionFromDelta()`][7].

[6]: https://github.com/microsoft/vscode/blob/e55f6c99ccb126137375cb1636a581d7678b85c3/src/vs/base/browser/ui/scrollbar/scrollbarState.ts#L195
[7]: https://github.com/microsoft/vscode/blob/e55f6c99ccb126137375cb1636a581d7678b85c3/src/vs/base/browser/ui/scrollbar/scrollbarState.ts#L208


## Taking a First Crack at the Problem

So here is the source of the function in question

    /**
     * Compute a desired `scrollPosition` such that `offset` ends up in the center of the slider.
     * `offset` is based on the same coordinate system as the `sliderPosition`.
     */
    public getDesiredScrollPositionFromOffset(offset: number): number {
        if (!this._computedIsNeeded) {
            // no need for a slider
            return 0;
        }

        let desiredSliderPosition = offset - this._arrowSize - this._computedSliderSize / 2;
        return Math.round(desiredSliderPosition / this._computedSliderRatio);
    }

Apparently `_computedSliderSize` is how many "units" of scroll bar space the
slider takes up, based on how long your file is vs. how much is being viewed.
The taller you make your screen, the bigger the slider will be (since each page
shows more lines).  And the longer your file gets, the smaller the slider gets.

When you click somewhere in the slider gutter, it tries to make that point the
center of what you are viewing...by subtracting half the represented slider
size (e.g. half a screen's worth of scroll-real-estate).  So if you click up at
the top of the scroll bar, you might get something negative...and you could be
over the bounds if you click at the bottom.  Apparently there is logic in
`setDesiredScrollPositionNow()` which takes this result and clips it.  e.g.
*"you might not get what you desired"*.

**For our new behavior, the first thing we need to know if the click was above
the slider or below it.**  The code path for clicking -on- it is different
since that event is sent to a DOM element specifically for the slider.  So
this is actually very easy if we just know where the slider was.  There are
two potential choices: the `ScrollbarState._scrollPosition` field and the
`ScrollbarState._computedSliderPosition`.  The latter is in the same coordinate
system as `offset` (e.g. before adjustment with `_computedSliderRatio`).

**Then it's just a matter of going up or down a page.**  This seems easy on
the surface...if the `_computedSliderSize` represents a page's worth of scroll
bar units, wouldn't you just add or subtract that much from the current
position?

Seems easy enough to try:

    /**
     * Compute a desired `scrollPosition` from if offset is before or after the slider position.
     * If offset is before slider, treat as a page up (or left).  If after, page down (or right).
     * `offset` is based on the same coordinate system as the `sliderPosition`.
     * `_computedSliderSize` is in the same units, and corresponds to a "page" of lines.
     */
    public getDesiredScrollPositionFromOffset(offset: number): number {
        if (!this._computedIsNeeded) {
            // no need for a slider
            return 0;
        }

        let correctedOffset = offset - this._arrowSize;  // compensate if has arrows
        let desiredSliderPosition = this._computedSliderPosition;
        if (correctedOffset < this._computedSliderPosition) {
            desiredSliderPosition -= this._computedSliderSize;  // page up or left
        } else {
            desiredSliderPosition += this._computedSliderSize;  // page down or right
        }
        return Math.round(desiredSliderPosition / this._computedSliderRatio);
    }

On first trying it out, seems to work pretty well!  Like the code that was
there before, it doesn't have to worry about asking for out-of-bounds locations
because that is clipped by `setDesiredScrollPositionNow()`.


## Foiled By Long Files

I suspected from the start that that rounding would likely be a problem.
Consider that an ideal solution would be that if you looked at the line number
at the top of your editor, and then did a click for a "Page Up", that line
would be the new bottom line.  (Or maybe just right off the screen--depending
on what definition of "Page Up" you are using.)

Here we aren't calculating in terms of lines, but speaking in terms of "offset
and slider position units"...which then are transformed by a factor (the
`_computedSliderRatio`) into "scroll position units".  This could introduce
rounding errors to where paging via the scroll bar caused you to overlap more
than a line each step, or worse--you'd not see some lines in the file by
scrolling this way.

But could it be "good enough" that no one would notice this wasn't invoking
a line-aware paging call?  I thought to try this out on a very long file that
I made to see...and...

...perhaps I should have predicted: *the scroll bar won't keep shrinking down
to invisibility as you increase the file size*.  It only gets so small at one
point, and so as your file gets longer it is less and less in proportion to
what a "page" is.  If you try to move a scroll bar's worth, you'll be moving
much more than a page.


## Calculating In Terms of "Scroll Position" vs. "Slider Position"

If the slider had a limit to how small it would get, it wasn't a trustworthy
indicator of a page size.  But did the `ScrollState` have other members that
might be more reliable?

We can still use the `offset` compared to `_computedSliderPosition` to get
the paging direction.  But then we can go straight to the scroll position
coordinate system, moving by `_visibleSize` from the `_scrollPosition`:

    /**
     * Compute a desired `scrollPosition` from if offset is before or after the slider position.
     * If offset is before slider, treat as a page up (or left).  If after, page down (or right).
     * `offset` and `_computedSliderPosition` are based on the same coordinate system.
     * `_visibleSize` corresponds to a "page" of lines in the returned coordinate system.
     */
    public getDesiredScrollPositionFromOffset(offset: number): number {
        if (!this._computedIsNeeded) {
            // no need for a slider
            return 0;
        }

        let correctedOffset = offset - this._arrowSize;  // compensate if has arrows
        let desiredScrollPosition = this._scrollPosition;
        if (correctedOffset < this._computedSliderPosition) {
            desiredScrollPosition -= this._visibleSize;  // page up/left
        } else {
            desiredScrollPosition += this._visibleSize;  // page down/right
        }
        return desiredScrollPosition;
    }

Trying this out on a 10,000 line file, the granularity is such that it still
moves to within one line of a page.  It may be that the scroll units are
proportioned to the lines well enough that this "just works"--even without
having to fall back to speaking in terms of literal lines.


## Hey, What's the `_arrowSize` About?

This relates to the feature of having arrows on the ends of the scroll bars...
which is turned off by default for some reason.  Because there was a correction
for the offset as `(offset - this._arrowSize)`, I kept it--despite not really
knowing the big picture of how it plays into the coordinate calculations.

For it to make a difference in the comparison here, the scroll bar would have
to be about as small as the arrows.  So to check and see if there was anything
obvious wrong, I enabled the arrows and then and made a really long file.  But
as I mentioned, the scroll bar only gets so small.  I didn't notice any problem
with the arrows turned on.


## Being Able to Turn On or Off?

For anyone who wants to "jump" to a source via a scroll panel, it seems the
code preview is a fine way to do it.  (I was glad that changing this scroll
bar behavior didn't change the code preview in the process.)

However, there might be some people who don't have the preview turned on...and
still want to be able to click to jump directly to a point "somewhere" in
the scroll bar?

I definitely think jumping by page should be the default.  But developers are
a picky bunch, so there might be someone who doesn't like it.

## Submitting as a PR...

I'm going ahead and submitting it.  Will see how it goes.
