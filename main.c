#include <philosophers.h>

void	func(void)
{
	system("leaks philo");
}

int	main(int argc, char *argv[])
{
	t_philo	*philos;

	atexit(func);
	if (argc < 5)
		return (usage_err(), 1);
	if (check_arguments(argv) == EOF)
		return (2);
	if (philos_init(&philos, argv) == 0)
		return (0);
	if (philos->nbr_of_meals == 0)
		return (clear(&philos), 0);
	if (launch(philos) == 0)
		return (clear(&philos), 3);
	clear(&philos);
	return (0);
}
