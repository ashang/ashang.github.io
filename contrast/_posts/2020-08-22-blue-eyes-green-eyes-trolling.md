---
title: "How Blue and Green Eye Island Trolled the Internet"
---

There's a puzzle that became Internet-famous [on xkcd][1] and [Terrence Tao's
blog][2].  I'd heard of it, and vaguely recall that I looked at it and skimmed
over the solution years ago.  But I didn't remember the details.

[1]: https://xkcd.com/blue_eyes.html
[2]: https://terrytao.wordpress.com/2008/02/05/the-blue-eyed-islanders-puzzle/

Since I want to get better at math, and had forgotten what the big fuss was
over this question, it crossed my mind to go look it up again.  (I chose the
less-violent xkcd formulation.)

Feel free to think about it yourself...or just be lazy and read [what is
claimed as the answer][3].

[3]: https://xkcd.com/solution.html

I *thought* I didn't have too much of a problem with it.  What I worked through
on my own was:

1. The guru can never know their eye color, and thus never leaves the island.

2. The symmetries of the problem dictate that everyone has equal information.
   So if one person of any eye color leaves the island on a given day, then all
   people with that eye color must leave that same day.

3. An islander can only communicate information to other islanders through the
   act of NOT leaving.

*(The obvious aspect of #3 is that islanders can't communicate to others with
the SAME eye color by the act of leaving--since they all leave at once.  But
going again with symmetry justifying #2, that leaving doesn't show anything
the people with the other eye color didn't already know either.  e.g. those who
stay must have been able to predict who would leave, just as easily as the
people who actually left did.)*

I figured that despite having such limited possible actions, the islanders can
still establish a convention through which they can transmit a number to each
other.


## The Power Of Protocol

To make use of their counting facility, the islanders have to mutually
conclude to use the same contract.  At least one possible contract is:

    "Each of us agrees to communicate to the group how many blue-eyed people
    we see by not leaving for (at least) that number of days."

With the numbers in the xckd puzzle, the situation after 99 days of this
protocol is that no one will have left yet.  At this point, everyone has become
aware that everyone else must have counted *at least* 99 blue-eyed people.

That means on the ninety-ninth day:

* A blue-eyed person sees only 99 blue-eyed people, so they've fulfilled their
  contract.  Up until this day they might have thought there was someone on the
  island who had counted 98 blue-eyed people...meaning they themselves had
  some other eye color.  As of today's count that's no longer an option.  So
  they know their own eyes must be blue.

* A brown-eyed person sees 100 blue-eyed people.  They've been participating in
  the count just like everyone, so in theory they'd have one more day to
  transmit their final number.  But they don't need to--*since everyone saw at
  least 99 blue-eyed people, including blue-eyed people themselves, then 100
  blue-eyed people was the final count*.  They aren't one.

On the 100th day, the blue-eyed people leave.  The brown-eyed people never
know their own eye color, and stay.

So with *this* contract, the 99th day is a turning point.  Blue-eyed people
have a Eureka moment of "*I* knew there were at least 99 blue-eyed people here,
but did not know *ALL of you* knew that...until now."  Because of the
symmetries in the problem, the brown-eyed people must have the same Eureka.

You can try this and find it works for numbers other than 100 (if that was not
obvious).


## Trolling on a Mass Scale?

Here's where my issues started.  I was having a hard time finding some sort of
*plain language* answer to this question:

    Why do the islanders have to wait 99 whole days, when they all know that
    no one is going to leave on the first day?

When you think of it as a protocol, you say "the protocol isn't finished, the
tipping point wasn't reached".  New information comes each day.  But that
appears to fly in the face of what's "obvious".

I was willing to believe that there were 99 hidden variables that were
multiplexed across all the "voting members" in the protocol.  And while I
couldn't see exactly how to formalize their collective haze that clarified and
eventually clicked, it wouldn't be surprising if when all the shards of
unknown-ness summed up to the right number due to symmetry.

So I gave up and started reading more about the problem, and *became utterly
confused*.  It seemed the more I looked at people arguing about it, the further
I was getting from an actual explanation.

**I'd been assuming that the guru could just as well have said "Protocol Blue:
Start Counting Today".**  This would give a color and a synchronization point.
But people were pointing to induction and insisting:

    Until the guru told them they could see a blue-eyed person...*the islanders
    could not be collectively certain there were any blue-eyed people at all*.

This is rather hard to believe.  One comment on the [Wikipedia talk page for
"Common Knowledge"][4] summed up the feelings of most skeptics:

    I feel like I'm being trolled on a mass scale.

    Everyone uses examples of 1 and 2 people, where it works, and then jumps to
    it working for k > 2, when it just doesn't. If k > 1, *everyone* already
    sees blue eyes, and the announcement doesn't introduce any new knowledge in
    any way.

    We are to assume the islanders can count the number of blue eyes people to
    induce the number of days to wait as k, but they have some inexplicable
    internal block that says despite everyone seeing at least one blue eye
    person (in k>2) they don't know it until the oracle states it explicitly?

[4]: https://en.wikipedia.org/w/index.php?title=Talk:Common_knowledge_(logic)&oldid=880549342

*(There is also a lengthy argument between "Jane Q. Public" and "SPACKlick",
which is an example of the sort of baffling lengths people seem to go to on
this topic.)*


## Benefits And Dangers of Problem Simplification

Like many people who look at this, it didn't actually occur to me that I could
break it down recursively.  My reason was that it feels kind of "interlocked";
people are looking all *at each other*.  It's as if there's a string connecting
each of the islanders...and you can't just go in and yank out one person and
all their strings.  You seem to risk changing the character of the problem.

This is echoed in the complaint I quote above; which says that breaking things
down through recursion cuts across intuitive points that apply in smaller
cases but not bigger ones.  For instance:

A. Two blue eyed people looking at each other CAN'T be sure that everyone can
   see at least one blue eyed person.

B. Three blue eyed people looking at each other CAN be sure that everyone can
   see at least one blue eyed person.

It feels incorrect to say that the way to show that (B) is actually false is to
have one of those three people remove themselves from consideration...at which
point it becomes no different than (A).

*And in this case, it FEELS incorrect because it WOULD be incorrect to try to
falisfy (B) using such a simplification.*  The situations are different, and
the statements are both true.

**But this is fundamentally not about knowing what everyone else can SEE, it's
about knowing what everyone else KNOWS.**

So the actual applicable statements are:

A. Two blue eyed people looking at each other CAN'T be sure that everyone can
   see at least one blue eyed person.

B. Three blue eyed people looking at each other CAN'T be sure that everyone can
   be sure they are looking at two people who are each certain the other is
   seeing at least one blue eyed person.

Some people suggest understanding why the guru's statement had meaning by
pointing out a version that *wouldn't* have been useful: which would be to
take each villager aside and go "Pssst...there's a blue eyed person on this
island."  They'd all say "I already knew that" and it would serve no point.

But when the guru makes the statement to everyone *in front of everyone*, it
removes any doubt of what the others know.  Everyone knows that everyone knows.


## Hopefully This Helps

Reading many "authoritative" explanations, I think there's not enough of a
lead-in to the rationale of why it's safe or correct to use recursion to break
down the problem.  That was certainly a sticking point for me.

But I'm comfortable with it now.  If you're reading this maybe you're not
there yet, but you'll get there.  :-)