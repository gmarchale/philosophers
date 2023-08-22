#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (parser(argc, argv) != 0)
		return (1);
	if (init_data(argc, argv, &data) != 0)
		return (1);
	if (init_philo_and_forks(&data) != 0)
		return (1);
	//monitoring
	join_threads(&data);
	return (0);
}
