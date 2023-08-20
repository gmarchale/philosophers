#include "../include/philosophers.h"

void	my_sleep(long time)
{
	long	i;

	i = get_time();
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

void	print_time(long start)
{
	long	time;

	time = get_time() - start;
	printf("%ld\n", time);
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
	print_time(data.start_time);
	return (0);
}
