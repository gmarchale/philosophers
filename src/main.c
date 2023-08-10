#include "../include/philosophers.h"

int	init_data(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->n_meals = -1;
	if (argc == 6)
		data->n_meals = ft_atoi(argv[5]);
	if (data->time_to_die == 0)
		return (1);
	return (0);
}

/*
int	create_philo(t_data *data)
{
}
*/

int	init_philo(t_data *data)
{
	t_philo	*philo;

	philo = malloc(data->n_philo * sizeof(t_philo));
	if (!philo)
		return (0); // error
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parser(argc, argv))
		return (1);
	init_data(argc, argv, &data);
	init_philo(&data);
	printf("---Fin de la main---\n");
	return (0);
}
