#include "../include/philosophers.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	nbr;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr = (nbr * 10) + str[i] - 48;
		i++;
	}
	return (sign * nbr);
}
