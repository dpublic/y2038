#ifndef POSTIME64_H
#    define POSTIME64_H

#include "time64.h"

/* Same function prototype as gmtime_r() */
/* convenience function only valid for positive time (post 1 January 1970) */
inline struct TM *gmpostime64_r(const time_t *in_time_t, struct TM *p)
{
	Time64_T in_time = (unsigned long)(*in_time_t);
	return gmtime64_r(&in_time, p);
}

/* Same function prototype as localtime_r() */
/* convenience function only valid for positive time (post 1 January 1970) */
inline struct TM *localpostime64_r(const time_t *in_time_t, struct TM *local_tm)
{
	Time64_T in_time = (unsigned long)(*in_time_t);
	return localtime64_r(&in_time, local_tm);
}

#endif
