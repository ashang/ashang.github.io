/* This program is a quick little launcher program for X.
 *
 * You run the program, it grabs the display (hopefully nothing else has it
 * grabbed), and you type what you want to run. The styling is minimalist.
 *
 * (c) 2003 Matt Johnston
 * matt (at) ucc.asn.au
 *
 * Compile it with 
 * cc thinglaunch.c -o thinglaunch -lX11 -L/usr/X11R6/lib -lpthread
 * (works for Linux and OSF/1 anyway, for static you might need -ldl, and you
 * mightn't need -lpthread.)
 *
 * This program can be freely distributed in source or binary form, under a
 * quite permissive license. See the bottom of this file for the full license.
 * If that license is too restrictive, mail me and you can choose another one.
 *
 * $Id: thinglaunch.c,v 1.8 2004/09/20 14:27:48 matt Exp $
 */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void createWindow();
static void setupGC();
static void eventLoop();
static void grabHack();
static void redraw();
static void keypress(XKeyEvent * keyevent);
static void execcmd();
static void die(const char* message);

/* Somewhat arbitrary. But important I guess if I end up changing it */
#define THINGLAUNCH_VERSION 1.03

Display * display;
GC gc;
GC rectgc;
Window win;
XFontStruct* font_info;
int screen_num;
unsigned long black, white;

#define MAXCMD 255
#define WINWIDTH 640
#define WINHEIGHT 25

/* the actual commandline */
char command[MAXCMD+1];

int main(int argc, char ** argv) {

	command[0] = 0x0;
	createWindow();

	setupGC();

	grabHack();

	eventLoop();

	/* don't return */
	return 1; /* keep compilers happy */

}

static void createWindow() {

	char *display_name;
	int display_width, display_height;
	int top, left;
	int borderwidth = 0;
	XSizeHints* win_size_hints;
	XSetWindowAttributes attrib;

	display_name = getenv("DISPLAY");
	if (display_name == NULL) {
		die("DISPLAY not set");
	}

	display = XOpenDisplay(display_name);
	if (display == NULL) {
		die("Couldn't connect to DISPLAY");
	}

	screen_num = DefaultScreen(display);
	display_width = DisplayWidth(display, screen_num);
	display_height = DisplayHeight(display, screen_num);

	top = (display_height/2 - WINHEIGHT/2);
	left = (display_width/2 - WINWIDTH/2);

	black = BlackPixel(display, screen_num);
	white = WhitePixel(display, screen_num);

	/*win = XCreateSimpleWindow(display, RootWindow(display, screen_num),
			left, top, WINWIDTH, WINHEIGHT, borderwidth, 
			black, black);*/

	attrib.override_redirect= True;
	win = XCreateWindow(display, RootWindow(display, screen_num),
			left, top, WINWIDTH, WINHEIGHT, 
			0, CopyFromParent,InputOutput,CopyFromParent,
			CWOverrideRedirect,&attrib);

	/* set up the window hints etc */
	win_size_hints = XAllocSizeHints();
	if (!win_size_hints) {
		die("out of memory allocating hints");
	}

	win_size_hints->flags = PMaxSize | PMinSize;
	win_size_hints->min_width = win_size_hints->max_width = WINWIDTH;

	win_size_hints->min_height = win_size_hints->max_height = WINHEIGHT;
	XSetWMNormalHints(display, win, win_size_hints);
	

	XFree(win_size_hints);

	XMapWindow(display, win);

}

static void setupGC() {

	XGCValues values;
	int valuemask = 0;
	int line_width = 1;
	int line_style = LineSolid;
	int cap_style = CapButt;
	int join_style = JoinBevel;
	char* font_name;

	gc = XCreateGC(display, win, valuemask, &values);
	rectgc = XCreateGC(display, win, valuemask, &values);
	XSetForeground(display, gc, white);
	XSetBackground(display, gc, black);

	XSetForeground(display, rectgc, black);
	XSetBackground(display, rectgc, black);

	XSetLineAttributes(display, gc, line_width, line_style, 
			cap_style, join_style);

	/* setup the font */
	font_name = "-misc-*-medium-r-*-*-15-*-*-*-*-*-*-*";
	font_info = XLoadQueryFont(display, font_name);
	if (!font_info) {
		die("couldn't load font");
	}

	XSetFont(display, gc, font_info->fid);
	
}


static void eventLoop() {
	
	XEvent e;

	redraw();

	XSelectInput(display, win, ExposureMask | KeyPressMask);

	for (;;) {
		XNextEvent(display, &e);
		switch(e.type) {
			case Expose:
				redraw();
				break;
			case KeyPress:
				keypress(&e.xkey);
				break;
			default:
				break;
		}

	}
}

/* this loop is required since pwm grabs the keyboard during the event loop */
static void grabHack() {

	int maxwait = 3000000; /* 3 seconds */
	int interval = 5000; /* 5 millisec */
	int i, x;

	redraw();

	/* if it takes longer than maxwait, just die */
	for (i = 0; i < (maxwait / interval); i++) {
		usleep(interval);
		x = XGrabKeyboard(display, win, False, GrabModeAsync, GrabModeAsync,
				CurrentTime);
		if (x == 0) {
			return;
		}
	}

	die("Couldn't grab keyboard");

}

static void redraw() {

	int font_height;
	int textwidth;
	
	font_height = font_info->ascent + font_info->descent;
	textwidth = XTextWidth(font_info, command, strlen(command));

	XFillRectangle(display, win, rectgc, 0, 0, WINWIDTH, WINHEIGHT);
	XDrawRectangle(display, win, gc, 0, 0, WINWIDTH-1, WINHEIGHT-1);
	XDrawString(display, win, gc, 2, font_height+2, command, strlen(command));
	XDrawLine(display, win, gc, 2 + textwidth, font_height + 2,
			2 + textwidth + 10, font_height+2);

	XFlush(display);


}

static void keypress(XKeyEvent * keyevent) {

#define KEYBUFLEN 20
	char buffer[KEYBUFLEN+1];
	KeySym key_symbol;
	int len;

	len = XLookupString(keyevent, buffer, 1, &key_symbol, NULL);
	buffer[len] = 0x0;

	switch(key_symbol) {
		case 0xff1b: /* this is escape */
			exit(0);
			break;
		case 0xff08: /* backspace */
			len = strlen(command);
			if (len > 0) {
				command[len-1] = 0x0;
			}
			break;
		case 0xff0d: /* enter */
			execcmd();
			break;
		default:
			break;
	}

	/* normal printable chars */
	if (key_symbol >= 0x20 && key_symbol <= 0x7e) {
		len = strlen(command);
		if (len < MAXCMD) {
			command[len] = buffer[0];
			command[len+1] = 0x0;
		}
	}
	redraw();

}

static void execcmd() {

	char * shell;
	char * argv[4];

	XDestroyWindow(display, win);
	
	if (fork()) {
		exit(0);
	}

	shell = getenv("SHELL");
	if (!shell) {
		shell = "/bin/sh";
	}

	argv[0] = basename(shell);
	argv[1] = "-c";
	argv[2] = command;
	argv[3] = NULL;

	execv(shell, argv);
	die("aiee, after exec");

}


static void die(const char* msg) {

	fprintf(stderr, "Error: %s\n", msg);
	exit(1);
}


/*
Copyright (c) 2003 Matt Johnston
All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
