#include "../include/philosophers.h"

void	free_philo_and_forks(t_data *data)
{
	free(data->philo);
	free(data->forks);
}

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
