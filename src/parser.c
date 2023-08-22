#include "../include/philosophers.h"

static int	parsing_error(int mode)
{
	if (mode == 1)
		printf("Wrong number of arguments\n");
	else if (mode == 404)
		printf("Wrong input\n");
	return (1);
}

int	check_arguments(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (parsing_error(404));
			j++;
		}
		i++;
	}
	return (0);
}

int	parser(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (parsing_error(1));
	if (ft_atoi(argv[1]) < 1)
		return (parsing_error(404));
	if (ft_atoi(argv[2]) < 1)
		return (parsing_error(404));
	return (check_arguments(argv));
}
