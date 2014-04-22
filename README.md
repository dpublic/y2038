y2038 postime64
===============

This is a fork of https://github.com/schwern/y2038 that includes a separate postime64.h file that defines convenience functions that are function replaceable to the standard gmtime_r() and localtime_r().
THESE CONVENIENCE FUNCTIONS REQUIRE THE INPUT TIME_T TIME TO BE POSITIVE IN THE UNSIGNED LONG RANGE (1 JANUARY 1970 TO 7 FEBRUARY 2106).
THEY WILL NOT SUPPORT NEGATIVE TIME (PRE 1970) IN 32 BIT OSES.

Here is a list of the currently implemented functions in postime64.h and
their POSIX time.h equivalents.

  postime64.h                      time.h
  -----------                      ------
  localpostime64_r()               localtime_r()
  gmpostime64_r()                  gmtime_r()

To install, simply copy postime64.h, time64.c, time64.h, time64_config.h, time64_limits.h into your project.
To use, replace the corresponding functions above.
Also, replace #include <time.h> and #include "time.h" (if not using a custom time.h file.) with:
#include "postime64.sh"

To test sample code, run "make" in testpostime64 directory and run the executable.


Limitations, Issues, etc...
---------------------------

As noted above, the functions cast the input time_t to unsigned long for 32 bit OSes so input time_t is only valid for positive time values (1 January 1970 to 7 February 2106).
For 64 bit OSes, there is no casting so the input time_t value can be the full 64 bit range (2,147,481,748 BC to 2,147,485,547 AD).
You must know if your application only uses positive time_t values for these functions to be replaceable.
If your applications use negative time_t values in 32 bit OSes or are unsure, you can fall back to the use of the 64 bit time input functions of the original y2038 code that is included here.
This will require more code changes than simply replacing functions.
Also, if your application uses time_t values in calculations that may result in a negative result, these functions will not work with those time_t results because they would be negative.
The bottom line is that you must know your code.
Finally, these functions built and run under 32 bit and 64 bit OSes will return the same result so the same code is portable.

