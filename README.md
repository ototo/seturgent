seturgent
=========

A simple command line tool that sets urgent window manager hint for a
window that is specified by its ID either as a parameter, or as an
environment variable named WINDOWID, which is usually set by terminal
emulators.

Can be quite useful to set urgency flag for terminal emulators that
do not support setting it on terminal bell.

Examples
--------

```sh
# set urgent hint for the window specified by WINDOWID
./seturgent
```

```sh
# set urgent hint for the window with ID = 238764
./seturgent 238764
```
