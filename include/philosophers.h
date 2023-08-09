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
	long			time_last_meal;
	int				c_meals;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	status;
	pthread_mutex_t	meal_time;
	//bool			end;
	long			start_time;
	int				num_p;
	int				time_d;
	int				time_e;
	int				time_s;
	int				num_e;
}	t_data;

/*** FUNCTIONS ***/

/* Parser */
int check_arguments(char **argv);
int parser(int argc, char **argv);

/* Atoi */
int	ft_atoi(const char *str);

#endif
