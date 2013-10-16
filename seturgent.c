/* Set urgency hint for the window specified by its ID or, if not
 * specified, for the most recent parent console window (using WINDOWID
 * environment variable).
 *
 * by Serge Broslavsky <serge.broslavsky@gmail.com>
 * under the WTFPL v2+ license.
 */

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int main(int argc, char **argv)
{
    Display* display = NULL;
    XWMHints* hints = NULL;
    Window wnd;
    int retval = 0;

    if (argc > 2) {
        printf("Usage: %s [<window_id>]\n", argv[0]);
        return 1;
    }

    display = XOpenDisplay(NULL);

    if (! display) {
        printf("Error: Unable to get a display.\n");
        return 2;
    }

    char* id_string = (argc == 2) ? argv[1] : getenv("WINDOWID");
    if (! id_string) {
        printf("No window ID is provided either as a parameter "
               "or as WINDOWID environment variable.\n");
        return 3;
    }

    wnd = atol(id_string);

    hints = XGetWMHints(display, wnd);

    if (! hints)
        hints = XAllocWMHints();

    if (! hints) {
        printf("Error: Unable to get WM hints\n");
        retval = 4;
        goto cleanup;
    }

    hints->flags |= XUrgencyHint;

    XSetWMHints(display, wnd, hints);

    XFree(hints);

cleanup:
    XCloseDisplay(display);

    return retval;
}
