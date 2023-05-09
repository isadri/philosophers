#include <philosophers.h>

int	main(int argc, char *argv[])
{
	t_philo	*philos;

	if (argc < 5)
		return (usage_err(), 1);
	if (check_arguments(argv) == EOF)
		return (2);
	philos_init(&philos, argv);
	if (philos->nbr_of_meals == 0)
		return (0);
	if (launch(philos) == 0)
		return (clear(&philos), 3);
	//print_data(philos);
	clear(&philos);
	//system("leaks philo");
	exit(EXIT_SUCCESS);
}
