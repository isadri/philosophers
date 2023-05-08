#include <philosophers.h>

bool	someone_dies(t_philo *philos, t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (get_current_time() - philos->time.current_time >= data->time_to_die)
			return (true);
		i++;
	}
	return (false);
}

bool	all_eat(t_philo *philos, t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (philos[i].eat_counter != data->max_eat)
			return (false);
		i++;
	}
	return (true);
}

