#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*** STRUCT ***/

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	_Atomic long	time_last_meal;
	_Atomic int		current_meal;
	struct s_data	*data; // Useless ? Not yet used. 
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	status;
	pthread_mutex_t	meal_time;
	//bool			end;
	long			start_time;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
}	t_data;

/*** FUNCTIONS ***/

/* Parser */
int check_arguments(char **argv);
int parser(int argc, char **argv);

/* Atoi */
int	ft_atoi(const char *str);

#endif
