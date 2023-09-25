
#include <X11/Xlib.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

inline void OWindow(Display *Dsp, int Scr, int Root, int x, int y, int height, int width, const char *BG) {
    // XCreate Window (Simple)
    int Black = BlackPixel(Dsp, Scr);
    int White = WhitePixel(Dsp, Scr);

	if (strcmp(BG, "black")) {
	    Window Win = XCreateSimpleWindow(Dsp, Root, x, y, width, height, 1, Black, White);
	    XMapWindow(Dsp, Win);
	} else {
	    Window Win = XCreateSimpleWindow(Dsp, Root, x, y, width, height, 1, White, Black);
	    XMapWindow(Dsp, Win);
	}
}

inline void Close(Display *Dsp) {
    XCloseDisplay(Dsp);
}

inline void WMapping(Display *Dsp, Window Win) {
    XMapWindow(Dsp, Win);
}

inline void UnMapping(Display *Dsp, Window Win) {
    XUnmapWindow(Dsp, Win);
}

inline void DestroyWin(Display *Dsp, Window Win) {
    XDestroyWindow(Dsp, Win);
}


// Data
#ifndef DATA_H
#define DATA_H

#define MAX_CHAR    200
#define WINDOW_NAME "Window"


typedef struct
{
    Display *Dsp;
    Window   Win;
    int	     Scr;
    XEvent   Xe;
} DspConf;

typedef struct
{
    float X;
    float Y;
    float HEIGHT;
    float WIDTH;
    char *NAME;
    int	  Root;

    int			 ColMap;
    Visual		*visual;
    int			 Depth;
    XSetWindowAttributes Attr;
} WinConf;

#endif // !DATA_H