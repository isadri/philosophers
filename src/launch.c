#include <philosophers.h>

static void	launch_philos(t_philo *philos, t_data *data);
static void	detach_philos(t_philo *philos, unsigned int nbr_of_philos);

void	launch(t_data *data)
{
	t_philo			*philos;

	philos = data->philos;
	launch_philos(philos, data);
	detach_philos(philos, data->nbr_of_philos);
	while (1);
	//while (!all_eat(philos, data))
	//	;
	while (!all_eat(philos, data) && !someone_dies(philos, data))
		;
}

static void	launch_philos(t_philo *philos, t_data *data)
{
	int				err;
	unsigned int	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		err = pthread_create(&(philos[i].ph), NULL, start, &(philos[i]));
		if (err != 0)
			exit_func_call_err("pthread_create", err);
		if ((i + 1) % 2 != 0)
			usleep(30);
		i++;
	}
}

static void	detach_philos(t_philo *philos, unsigned int nbr_of_philos)
{
	int				err;
	unsigned int	i;

	i = 0;
	while (i < nbr_of_philos)
	{
		err = pthread_detach((philos[i].ph));
		if (err != 0)
			exit_func_call_err("pthread_detach", err);
		i++;
	}
}

time_t	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (perror("gettimeofday"), 0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

time_t	get_action_time(t_philo *philo)
{
	return (get_current_time() - philo->start_time);
}
