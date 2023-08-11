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


t_philo	create_philo(int i)
{
	t_philo	philo;

	philo.id = i;
	return (philo);
}

int	init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = NULL;
	philo = malloc(data->n_philo * sizeof(t_philo));
	if (philo == NULL)
		return (1); // error malloc
	i = 0;
	while (i < data->n_philo)
	{
		philo[i] = create_philo(i);
		// create thread for each philo
		printf("Philo.id = %d\n", philo[i].id);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parser(argc, argv))
		return (1);
	init_data(argc, argv, &data);
	init_philo(&data);
	// free les philos
	printf("---Fin de la main---\n");
	return (0);
}
