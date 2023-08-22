#include "../include/philosophers.h"

void	change_end(t_data *data)
{
	pthread_mutex_lock(&data->status);
	data->end = true;
	pthread_mutex_unlock(&data->status);
}

void	set_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_time);
	philo->time_last_meal = get_time();
	pthread_mutex_unlock(&philo->data->meal_time);
}

long	read_meal_time(t_philo *philo)
{
	long	last_meal_time;

	pthread_mutex_lock(&philo->data->meal_time);
	last_meal_time = philo->time_last_meal;
	pthread_mutex_unlock(&philo->data->meal_time);
	return (last_meal_time);
}

int	sub_monitoring(t_data *data)
{
	int		i;
	long	diff_meal;

	i = 0;
	while (i < data->n_philo)
	{
		diff_meal = get_time() - read_meal_time(&data->philo[i]);
		if (data->time_to_die < diff_meal)
		{
			change_end(data);
			if (data->philo[i].current_meal != 0)
				printf("%ld ms Philo %d has died\n",
					time_elapsed(data->start_time), data->philo[i].id);
			return (1);
		}
		i++;
	}
	return (0);
}

int	monitoring(t_data *data)
{
	while (!check_end(data))
	{
		if (sub_monitoring(data))
		{
			free_philo_and_forks(data);
			return (1);
		}
		usleep(1000);
	}
	free_philo_and_forks(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parser(argc, argv) != 0)
		return (1);
	if (init_data(argc, argv, &data) != 0)
		return (1);
	if (init_philo_and_forks(&data) != 0)
		return (1);
	if (monitoring(&data))
		return (1);
	join_threads(&data);
	return (0);
}
