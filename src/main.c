#include "../include/philosophers.h"

uint64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	my_sleep(uint64_t time)
{
	uint64_t	i;

	i = get_time();
	printf("%llu\n", i);
	while (1)
	{
		if (get_time() - i >= time)
			break ;
		usleep(100);
	}
}

void *life(void *tmp)
{
	t_philo *philo;

	philo = tmp;
	if (philo->id % 2 == 1)
		my_sleep(50);
	/*
	while (1)
		if (philo_routine(philo))
			break ;
			*/
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	printf("---Debut de la main---\n");
	if (parser(argc, argv) != 0)
		return (1);
	if (init_data(argc, argv, &data) != 0)
		return (1);
	if (init_philo_and_forks(&data) != 0)
		return (1);
	//monitoring
	join_threads(&data);
	printf("---Fin de la main---\n");
	return (0);
}
