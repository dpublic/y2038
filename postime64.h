/*
	postime64.h

	positive time only convenience functions
	valid for positive time (1 January 1970 to 7 February 2106) for 32 bit OS
	valid for all time (2,147,481,748 BC to 2,147,485,547 AD) for 64 bit OS
*/

#ifndef POSTIME64_H
#define POSTIME64_H

#ifndef __GNUC__
#define __inline__ inline
#endif

#include "time64.h"

/* Same function prototype as standard gmtime_r() */
__inline__ struct TM *gmpostime64_r(const time_t *in_time_t, struct TM *p)
{
	Time64_T in_time;

	if (sizeof(time_t) == 4)
	{
		/* convert to positive time only for 32 bit OS */
		in_time = (unsigned long)(*in_time_t);
	}
	else
	{
		/* leave time as is for 64 bit OS */
		in_time = *in_time_t;
	}

	return gmtime64_r(&in_time, p);
}

/* Same function prototype as standard localtime_r() */
__inline__ struct TM *localpostime64_r(const time_t *in_time_t, struct TM *local_tm)
{
	Time64_T in_time;

	if (sizeof(time_t) == 4)
	{
		/* convert to positive time only for 32 bit OS */
		in_time = (unsigned long)(*in_time_t);
	}
	else
	{
		/* leave time as is for 64 bit OS */
		in_time = *in_time_t;
	}

	return localtime64_r(&in_time, local_tm);
}

#endif
