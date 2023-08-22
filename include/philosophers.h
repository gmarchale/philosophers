/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:02:29 by gmarchal          #+#    #+#             */
/*   Updated: 2023/08/22 18:03:09 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

/*** STRUCT ***/

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	_Atomic long	time_last_meal;
	_Atomic int		current_meal;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	status;
	pthread_mutex_t	meal_time;
	bool			end;
	long			start_time;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
}	t_data;

/*** FUNCTIONS ***/

/* Parser */
int		check_arguments(char **argv);
int		parser(int argc, char **argv);

/* Init */
int		init_data(int argc, char **argv, t_data *data);
int		init_philo_and_forks(t_data *data);

/* Utils */
void	free_philo_and_forks(t_data *data);
int		join_threads(t_data *data);
void	set_meal_time(t_philo *philo);
int		ft_atoi(const char *str);

/* Time */
long	get_time(void);
long	time_elapsed(long start);
void	my_sleep(long time);

/* Philo */
void	*life(void *tmp);

/* Monitoring */
int		check_end(t_data *data);
int		monitoring(t_data *data);

#endif
