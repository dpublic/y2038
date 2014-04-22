#include <stdio.h>
#include "../postime64.h"


int GetTimeDiff(time_t a_start_time, time_t a_stop_time)
{
	double l_timediff = 0;

	if (a_start_time && a_stop_time)
	{
		l_timediff = difftime(a_stop_time, a_start_time);
	}

	return((int) l_timediff);
}


int main(int argc, char **argv)
{
	char timeBuf1[20];
	char timeBuf2[20];
	char timeBuf3[20];
	char timeBuf4[20];
	char timeBuf5[20];
	char timeBuf6[20];
	char timeBuf7[20];
	char timeBuf8[20];
	char timeBuf9[20];
	char timeBuf10[20];
	char timeBuf11[20];
	char timeBuf12[20];
	char timeBuf13[20];
	char timeBuf14[20];
	char timeBuf15[20];
	char timeBuf16[20];
	struct tm tm1;
	struct tm tm2;
	struct tm tm3;
	struct tm tm4;
	struct tm tm5;
	struct tm tm6;
	struct tm tm7;
	struct tm tm8;
	struct tm tm9;
	struct tm tm10;
	struct tm tm11;
	struct tm tm12;
	struct tm tm13;
	struct tm tm14;
	struct tm tm15;
	struct tm tm16;

	time_t current_time;

	current_time = time(NULL);
	time_t time1 = 0x7FFFFFFF;
	time_t time2 = 0x80000000;	/* overflow */
	time_t time3 = 0xFFFFFFFF;	/* overflow */
	time_t time4 = 0x80000001;	/* overflow */


	unsigned long time1unsigned = 0x7FFFFFFF;
	time_t time1signed = time1unsigned;
	printf("good:\ntime1unsigned = %lu\ntime1signed = %ld\n", time1unsigned, time1signed);

	unsigned long time2unsigned = 0x80000000;
	time_t time2signed = time2unsigned;
	printf("overflow:\ntime2unsigned = %lu\ntime2signed = %ld\n", time2unsigned, time2signed);

	unsigned long time3unsigned = 0xFFFFFFFF;
	time_t time3signed = time3unsigned;
	printf("overflow:\ntime3unsigned = %lu\ntime3signed = %ld\n", time3unsigned, time3signed);

	printf("overflow:\ndifftime(time4, time2) = %d\n", GetTimeDiff(time2, time4));


	gmtime_r(&current_time, &tm1);
	strftime(timeBuf1, 20, "%Y%m%d_%H%M%S", &tm1);

	printf("current standard gmtime_r()      :\ttimeBuf1:\t%s\n", timeBuf1);

	gmpostime64_r(&current_time, &tm2);
	strftime(timeBuf2, 20, "%Y%m%d_%H%M%S", &tm2);

	printf("current postime64 gmpostime64_r():\ttimeBuf2:\t%s\n", timeBuf2);

	gmtime_r(&time1, &tm3);
	strftime(timeBuf3, 20, "%Y%m%d_%H%M%S", &tm3);

	printf("time1 standard gmtime_r()        :\ttimeBuf3:\t%s\ttm_year = %d\n", timeBuf3, tm3.tm_year);

	gmpostime64_r(&time1, &tm4);
	strftime(timeBuf4, 20, "%Y%m%d_%H%M%S", &tm4);

	printf("time1 postime64 gmpostime64_r()  :\ttimeBuf4:\t%s\ttm_year = %d\n", timeBuf4, tm4.tm_year);

	gmtime_r(&time2, &tm5);
	strftime(timeBuf5, 20, "%Y%m%d_%H%M%S", &tm5);

	printf("time2 standard gmtime_r()        :\ttimeBuf5:\t%s\ttm_year = %d\n", timeBuf5, tm5.tm_year);

	gmpostime64_r(&time2, &tm6);
	strftime(timeBuf6, 20, "%Y%m%d_%H%M%S", &tm6);

	printf("time2 postime64 gmpostime64_r()  :\ttimeBuf6:\t%s\ttm_year = %d\n", timeBuf6, tm6.tm_year);

	gmtime_r(&time3, &tm7);
	strftime(timeBuf7, 20, "%Y%m%d_%H%M%S", &tm7);

	printf("time3 standard gmtime_r()        :\ttimeBuf7:\t%s\ttm_year = %d\n", timeBuf7, tm7.tm_year);

	gmpostime64_r(&time3, &tm8);
	strftime(timeBuf8, 20, "%Y%m%d_%H%M%S", &tm8);

	printf("time3 postime64 gmpostime64_r()  :\ttimeBuf8:\t%s\ttm_year = %d\n", timeBuf8, tm8.tm_year);


	localtime_r(&current_time, &tm9);
	strftime(timeBuf9, 20, "%Y%m%d_%H%M%S", &tm9);

	printf("current standard localtime_r()      :\ttimeBuf9:\t%s\n", timeBuf9);

	localpostime64_r(&current_time, &tm10);
	strftime(timeBuf10, 20, "%Y%m%d_%H%M%S", &tm10);

	printf("current postime64 localpostime64_r():\ttimeBuf10:\t%s\n", timeBuf10);

	localtime_r(&time1, &tm11);
	strftime(timeBuf11, 20, "%Y%m%d_%H%M%S", &tm11);

	printf("time1 standard localtime_r()        :\ttimeBuf11:\t%s\ttm_year = %d\n", timeBuf11, tm11.tm_year);

	localpostime64_r(&time1, &tm12);
	strftime(timeBuf12, 20, "%Y%m%d_%H%M%S", &tm12);

	printf("time1 postime64 localpostime64_r()  :\ttimeBuf12:\t%s\ttm_year = %d\n", timeBuf12, tm12.tm_year);

	localtime_r(&time2, &tm13);
	strftime(timeBuf13, 20, "%Y%m%d_%H%M%S", &tm13);

	printf("time2 standard localtime_r()        :\ttimeBuf13:\t%s\ttm_year = %d\n", timeBuf13, tm13.tm_year);

	localpostime64_r(&time2, &tm14);
	strftime(timeBuf14, 20, "%Y%m%d_%H%M%S", &tm14);

	printf("time2 postime64 localpostime64_r()  :\ttimeBuf14:\t%s\ttm_year = %d\n", timeBuf14, tm14.tm_year);

	localtime_r(&time3, &tm15);
	strftime(timeBuf15, 20, "%Y%m%d_%H%M%S", &tm15);

	printf("time3 standard localtime_r()        :\ttimeBuf15:\t%s\ttm_year = %d\n", timeBuf15, tm15.tm_year);

	localpostime64_r(&time3, &tm16);
	strftime(timeBuf16, 20, "%Y%m%d_%H%M%S", &tm16);

	printf("time3 postime64 localpostime64_r()  :\ttimeBuf16:\t%s\ttm_year = %d\n", timeBuf16, tm16.tm_year);


	return 0;
}

