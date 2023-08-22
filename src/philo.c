#include "../include/philosophers.h"

static int find_r_fork(t_philo *philo)
{
	if (philo->id == philo->data->n_philo - 1)
		return (0);
	else
		return (philo->id + 1);
}

static void	ft_sleep(int time)
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

void	print_message(char *str, int id, t_data *data, long ms)
{
	pthread_mutex_lock(&data->status);
	if (!data->end)
		printf("%ld ms Philo %i %s\n", ms, id, str);
	pthread_mutex_unlock(&data->status);
}

static int	ft_eat(t_philo *philo)
{
	int	r_fork;

	r_fork = find_r_fork(philo);
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	print_message("has picked up a fork", philo->id, philo->data,
		time_elapsed(philo->data->start_time));
	pthread_mutex_lock(&philo->data->forks[r_fork]);
	print_message("has picked up a fork", philo->id, philo->data,
		time_elapsed(philo->data->start_time));
	set_meal_time(philo);
	philo->current_meal--;
	print_message("is eating", philo->id, philo->data,
		time_elapsed(philo->data->start_time));
	ft_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[r_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->id]);
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
		if (check_end(philo->data))
			return (NULL);
		printf("%lu ms Philo %d is thinking\n", time_elapsed(philo->data->start_time), philo->id);
		printf("%lu ms Philo %d is sleeping\n", time_elapsed(philo->data->start_time), philo->id);
		ft_sleep(philo->data->time_to_sleep);
	}
	return (NULL);
}
