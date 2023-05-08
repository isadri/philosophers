#include <philosophers.h>

void	print_data(t_data *data)
{
	printf("nbr_of_philos: %u\n\n", data->nbr_of_philos);
	print_philos(data->philos, data->nbr_of_philos);
	printf("\neat_counter: %u\n", data->max_eat);
}

void	print_philos(t_philo *philos, int nbr)
{
	for (int i = 0; i < nbr; i++)
	{
		printf("philo id: %d\n", i + 1);
		printf("time_to_eat: %ld\n", philos->time.time_to_eat);
		printf("time_to_sleep: %ld\n", philos->time.time_to_sleep);
		printf("left_fork: %d\n", i + 1);
		printf("right_fork: %d\n", (i + 1) % 5 + 1);
		printf("\t-----------\n");
	}
}
