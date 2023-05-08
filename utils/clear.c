#include <philosophers.h>

void	clear(t_data **data)
{
	//destroy_forks((*data)->forks, (*data)->nbr_of_philos);
	free((*data)->forks);
	free((*data)->philos);
	free(*data);
}

void	destroy_forks(pthread_mutex_t *forks, unsigned int nbr_of_forks)
{
	int		err;
	unsigned int	i;

	i = 0;
	while (i < nbr_of_forks)
	{
		err = pthread_mutex_destroy(&(forks[i]));
		if (err != 0)
			exit_func_call_err("pthread_mutex_destroy", err);
		i++;
	}
}
