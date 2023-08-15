#include "../include/philosophers.h"

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

	join_threads(&data);
	printf("---Fin de la main---\n");
	return (0);
}
