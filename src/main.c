#include "../include/philosophers.h"

int init_data(int argc, char **argv, t_data *data)
{
	data->num_p = ft_atoi(argv[1]);
	data->time_d = ft_atoi(argv[2]);
	data->time_e = ft_atoi(argv[3]);
	data->time_s = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_e = ft_atoi(argv[5]);
	else
		data->num_e = 0;
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
