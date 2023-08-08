#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/*** STRUCT ***/

typedef struct s_philo
{
	int	philo_id;
}	t_philo;

/*** FUNCTIONS ***/

/* Parser */
int check_arguments(char **argv);
int parser(int argc, char **argv);

#endif
