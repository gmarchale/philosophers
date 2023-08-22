#include "../include/philosophers.h"

int	check_end(t_data *data)
{
	int	status;

	pthread_mutex_lock(&data->status);
	if (data->end)
		status = 1;
	else
		status = 0;
	pthread_mutex_unlock(&data->status);
	return (status);
}
