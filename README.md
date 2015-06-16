CONVERSION
----------
This is a program I wrote a long time ago. Its primary purpose was to convert binary to hexadecimal to help me make
xcb's. One of the goals of this program was to use my own algorithms to do the conversion, I will probably go ahead and
add a option to produce the conversion using shortcuts though.

BUILD
-----
gcc -std=c11 -lm main.c

TODO (these are pretty well in order of what should be done next)
----
* implement atoi and decimal check
* make things print nicer
* work on negative numbers
* add a predication
    * be able to figure out what type the user inputed
* add a loop
* add invert option
    * on one of my computer's the xcb's are inverted?
    * so this would mean just invert the binary
* add reverse
    * xcb's have the binary reversed
    * reverse the binary
