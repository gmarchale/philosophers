#include "../include/philosophers.h"

long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	time_elapsed(long start)
{
	return (get_time() - start);
}
