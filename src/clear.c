#include <philosophers.h>

void	clear(t_philo **philos)
{
	free((*philos)->mtx.head_forks_mtx);
	free((*philos)->mtx.head_meal_mtx);
	free((*philos)->mtx.print_mtx);
	free((*philos)->mtx.time_mtx);
	free(*philos);
}
