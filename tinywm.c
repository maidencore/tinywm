#include <X11/Xlib.h>

#define MOD_KEY Mod1Mask

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
	Display * dpy;
	XWindowAttributes attr;
	XButtonEvent start;
	XEvent ev;

	if (!(dpy = XOpenDisplay(0x0))) { return 1; }

	XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F1")), MOD_KEY,
		DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
	XGrabButton(dpy, 1, MOD_KEY, DefaultRootWindow(dpy), True,
		ButtonPressMask|ButtonReleaseMask|PointerMotionMask,
		GrabModeAsync, GrabModeAsync, None, None);
	XGrabButton(dpy, 3, MOD_KEY, DefaultRootWindow(dpy), True,
		ButtonPressMask|ButtonReleaseMask|PointerMotionMask,
		GrabModeAsync, GrabModeAsync, None, None);

	start.subwindow = None;
	for (;;) {
		XNextEvent(dpy, &ev);
		switch (ev.type) {
		case KeyPress:
			XSetInputFocus(dpy, (ev.xkey.subwindow == None ?
					PointerRoot : ev.xkey.subwindow),
				RevertToPointerRoot, CurrentTime);
			break;
		case ButtonPress:
			if (ev.xbutton.subwindow == None) { break; }
			XRaiseWindow(dpy, ev.xbutton.subwindow);
			XGetWindowAttributes(dpy, ev.xbutton.subwindow, &attr);
			start = ev.xbutton;
			break;
		case MotionNotify:
			if (start.subwindow == None) { break; }
			int xdiff = ev.xbutton.x_root - start.x_root;
			int ydiff = ev.xbutton.y_root - start.y_root;
			XMoveResizeWindow(dpy, start.subwindow,
				attr.x + (start.button == 1 ? xdiff : 0),
				attr.y + (start.button == 1 ? ydiff : 0),
				MAX(1, attr.width +
					(start.button == 3 ? xdiff : 0)),
				MAX(1, attr.height +
					(start.button == 3 ? ydiff : 0)));
			break;
		case ButtonRelease:
			start.subwindow = None;
			break;
		}
	}
}

