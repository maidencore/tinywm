/*
 * example program to demonstrate passing grabbed events
 * through to the underlying window
 */

#include <X11/Xlib.h>

int main(void) {
	Display * dpy;
	XEvent ev;

	if (!(dpy = XOpenDisplay(0x0))) { return 1; }

	XGrabButton(dpy, 1, AnyModifier, DefaultRootWindow(dpy), True,
		ButtonPressMask, GrabModeSync, GrabModeAsync, None, None);

	for (;;) {
		XNextEvent(dpy, &ev);
		if (ev.type == ButtonPress) {
			XSetInputFocus(dpy, (ev.xbutton.subwindow == None ?
				PointerRoot : ev.xbutton.subwindow),
				RevertToPointerRoot, CurrentTime);
		}
		XAllowEvents(dpy, ReplayPointer, ev.xbutton.time);
	}
}
