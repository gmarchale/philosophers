#include "../include/philosophers.h"

int main(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	if (parser(argc, argv))
		return (1);
	//if (init(argc, argv, &philo))
	//	return (2);
	printf("--->Fin de la main\n");
	return (0);
}
