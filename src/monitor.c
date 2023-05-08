#include <philosophers.h>

bool	someone_dies(t_philo *philos, t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nbr_of_philos)
	{
		if (get_current_time() - philos[i].time.last_time >= data->time_to_die)
			return (printf("%ld %u dies\n", get_action_time(philos + i), philos[i].id), true);
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
		if (philos[i].eat_counter != data->philos->nbr_of_meals)
			return (false);
		i++;
	}
	return (true);
}
