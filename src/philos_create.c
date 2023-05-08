#include <philosophers.h>

static void			set_time(t_philo *philo, time_t start_time, char *argv[]);
static void			set_left_right_forks(t_philo *philo, t_data *data, int i);
static unsigned int	get_nbr_of_meals(char *arg);

t_philo	*philos_create(char *argv[], t_data *data, int nbr)
{
	t_philo	*philos;
	int		i;

	philos = ft_calloc(nbr, sizeof(t_philo));
	i = -1;
	while (++i < nbr)
	{
		//philos[i].ph = ft_calloc(1, sizeof(pthread_t));
		philos[i].id = i + 1;
		philos[i].eat_counter = 0;
		philos[i].nbr_of_meals = get_nbr_of_meals(argv[5]);
		set_time(&philos[i], data->start_time, argv);
		set_left_right_forks(philos, data, i);
	}
	return (philos);
}

static void	set_time(t_philo *philo, time_t start_time, char *argv[])
{
	philo->time.time_to_eat = ft_atoi(argv[3]) * 1000;
	philo->time.time_to_sleep = ft_atoi(argv[4]) * 1000;
	philo->start_time = start_time;
}

static void	set_left_right_forks(t_philo *philo, t_data *data, int i)
{
	philo[i].left_fork = &(data->forks[i]);
	philo[i].right_fork = &(data->forks[(i + 1) % data->nbr_of_philos]);
}

static unsigned int	get_nbr_of_meals(char *arg)
{
	if (arg == NULL)
		return (1);
	return (ft_atoi(arg));
}