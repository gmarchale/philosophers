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


static int	malloc_philo_and_forks(t_data *data)
{
	if (pthread_mutex_init(&data->status, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->meal_time, NULL) != 0)
		return (1);
	data->philo = malloc(data->n_philo * sizeof(t_philo));
	if (data->philo == NULL)
		return (1);
	data->forks = malloc(data->n_philo * sizeof(pthread_mutex_t));
	if (data->forks == NULL)
	{
		free(data->philo);
		return (1);
	}
	return (0);
}

static int	create_philo(t_data *data, int i)
{
	data->philo[i].id = i;
	data->philo[i].time_last_meal = 0; //find_ms()
	data->philo[i].current_meal = 0;
	if (pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]))
		return (1);
	return (0);
}

int	init_philo_and_forks(t_data *data)
{
	int	i;

	if (malloc_philo_and_forks(data))
		return (1);
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL))
		{
			free_philo_and_forks(data);
			return (1);
		}
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (create_philo(data, i))
		{
			free_philo_and_forks(data);
			return (1);
		}
		i++;
	}
	return (0);
}
