#include "../include/philosophers.h"

int init_data(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->n_meals = ft_atoi(argv[5]);
	else
		data->n_meals = 0;
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (parser(argc, argv))
		return (1);
	init_data(argc, argv, &data);
	printf("---Fin de la main---\n");
	return (0);
}
