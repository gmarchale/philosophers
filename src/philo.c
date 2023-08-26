/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <gmarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:06:50 by gmarchal          #+#    #+#             */
/*   Updated: 2023/08/25 15:45:39 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	find_r_fork(t_philo *philo)
{
	if (philo->id == philo->data->n_philo - 1)
		return (0);
	else
		return (philo->id + 1);
}

void	print_message(char *str, int id, t_data *data, long ms)
{
	pthread_mutex_lock(&data->status);
	ms = time_elapsed(data->start_time);
	if (!data->end)
		printf("%ld ms Philo %i %s\n", ms, id, str);
	pthread_mutex_unlock(&data->status);
}

static int	ft_eat(t_philo *philo)
{
	int	r_fork;

	r_fork = find_r_fork(philo);
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	print_message("has picked up a fork", philo->id, philo->data, 0);
	if (r_fork == 0 && philo->id == 0)
	{
		my_sleep(philo->data->time_to_die);
		return (1);
	}
	pthread_mutex_lock(&philo->data->forks[r_fork]);
	print_message("has picked up a fork", philo->id, philo->data, 0);
	set_meal_time(philo);
	philo->current_meal--;
	print_message("is eating", philo->id, philo->data, 0);
	my_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->forks[r_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->id]);
	return (0);
}

void	*life(void *tmp)
{
	t_philo	*philo;

	philo = tmp;
	if (philo->id % 2 == 1)
		my_sleep(50);
	while (!check_end(philo->data) && philo->current_meal != 0)
	{
		if (ft_eat(philo))
			return (NULL);
		if (check_end(philo->data))
			return (NULL);
		print_message("is thinking", philo->id, philo->data, 0);
		print_message("is sleeping", philo->id, philo->data, 0);
		my_sleep(philo->data->time_to_sleep);
	}
	return (NULL);
}
