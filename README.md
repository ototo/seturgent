seturgent
=========

A simple command line tool that sets urgent window manager hint for a
window that is specified by its ID either as a parameter, or as an
environment variable named WINDOWID, which is usually set by terminal
emulators.

Can be quite useful to set urgency flag for terminals, which do not
support setting it on terminal bell.

EXAMPLES

./seturgent
    set urgent hint for the window specified by WINDOWID

./seturgent 238764
    set urgent hint fot the window with ID = 238764
