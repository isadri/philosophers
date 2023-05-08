#include <philosophers.h>

static pthread_mutex_t	*forks_create(int nbr);
static void				forks_init(pthread_mutex_t *forks, int nbr);

void	data_init(t_data **data, char *argv[])
{
	int				nbr_of_philos;
	struct timeval	tv;

	nbr_of_philos = ft_atoi(argv[1]);
	*data = ft_calloc(1, sizeof(t_data));
	if (gettimeofday(&tv, NULL) == -1)
		exit(EXIT_FAILURE);
	(*data)->nbr_of_philos = nbr_of_philos;
	(*data)->time_to_die = ft_atoi(argv[2]) * 1000;
	(*data)->forks = forks_create(nbr_of_philos);
	(*data)->start_time = get_current_time();
	(*data)->philos = philos_create(argv, *data, nbr_of_philos);
}

static pthread_mutex_t	*forks_create(int nbr)
{
	pthread_mutex_t	*forks;

	forks = ft_calloc(nbr, sizeof(pthread_mutex_t));
	forks_init(forks, nbr);
	return (forks);
}

static void	forks_init(pthread_mutex_t *forks, int nbr)
{
	int	err;
	int	i;

	i = -1;
	while (++i < nbr)
	{
		err = pthread_mutex_init(&forks[i], NULL);
		if (err != 0)
			exit_func_call_err("pthread_mutex_init", err);
	}
}
