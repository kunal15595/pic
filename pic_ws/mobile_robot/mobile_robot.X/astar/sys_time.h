#ifndef __SYS_TIME_H
#define __SYS_TIME_H
struct timeval {
	long	tv_sec;		/* seconds */
	long	tv_usec;	/* and microseconds */
};

struct timezone {
	int	tz_minuteswest;	/* minutes west of Greenwich */
	int	tz_dsttime;	/* type of dst correction */
};

int gettimeofday (struct timeval *, void *);
#endif
