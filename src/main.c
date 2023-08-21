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

int	check_end(t_data *data)
{
	int	status;

	pthread_mutex_lock(&data->status);
	if (data->end)
		status = 1;
	else
		status = 0;
	pthread_mutex_unlock(&data->status);
	return (status);
}

int find_r_fork(t_philo *philo)
{
	if (philo->id == philo->data->n_philo - 1)
		return (0);
	else
		return (philo->id + 1);
}

void	ft_sleep(int time)
{
	long	start;
	long	elapsed;

	start = get_time();
	elapsed = 0;
	while (elapsed < time)
	{
		usleep(time * 1000);
		elapsed = get_time() - start;
	}
}

int	ft_eat(t_philo *philo)
{
	int r_fork;

	r_fork = find_r_fork(philo);
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	printf("%lu ms Philo %d has taken left fork\n", time_elapsed(philo->data->start_time), philo->id);
	pthread_mutex_lock(&philo->data->forks[r_fork]);
	printf("%lu ms Philo %d has taken right fork\n", time_elapsed(philo->data->start_time), philo->id);
	philo->current_meal--;
	pthread_mutex_lock(&philo->data->meal_time);
	philo->time_last_meal = get_time();
	pthread_mutex_unlock(&philo->data->meal_time);
	printf("%lu ms Philo %d is eating\n", time_elapsed(philo->data->start_time), philo->id);
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->id]);
	pthread_mutex_unlock(&philo->data->forks[r_fork]);
	return (0);
}

void *life(void *tmp)
{
	t_philo *philo;

	philo = tmp;
	if (philo->id % 2 == 1)
		my_sleep(50);
	while (!check_end(philo->data) && philo->current_meal != 0)
	{
		ft_eat(philo);
		printf("%lu ms Philo %d is thinking\n", time_elapsed(philo->data->start_time), philo->id);
		printf("%lu ms Philo %d is sleeping\n", time_elapsed(philo->data->start_time), philo->id);
		ft_sleep(philo->data->time_to_sleep);
		printf("%lu ms Philo %d finished sleeping\n", time_elapsed(philo->data->start_time), philo->id);
	}
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
