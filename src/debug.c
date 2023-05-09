#include <philosophers.h>

void	print_data(t_philo *philos)
{
	unsigned int	nbr;
	unsigned int	i;

	nbr = philos->nbr_of_philos;
	i = 0;
	while (i < nbr)
	{
		printf("id: %u\n", philos[i].id);
		printf("nbr_of_meals: %d\n", philos[i].nbr_of_meals);
		printf("nbr_of_philos: %u\n", philos[i].nbr_of_philos);
		printf("time_to_die: %ld\n", philos[i].time.time_to_die);
		printf("time_to_eat: %ld\n", philos[i].time.time_to_eat);
		printf("time_to_sleep: %ld\n", philos[i].time.time_to_sleep);
		printf("start_time: %ld\n", philos[i].time.start_time);
		printf("last_eat_time: %ld\n\n", philos[i].time.last_eat_time);
		i++;
	}
}
