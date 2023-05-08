#include <philosophers.h>

static void	eat(t_philo *philo);
static void	sleep_and_think(t_philo *philo);
static void	acquire(t_philo *philo);
static void	release(t_philo *philo);

void	*start(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	eat(philo);
	sleep_and_think(philo);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	acquire(philo);
	printf("%ld %d has taken a fork\n", get_action_time(philo), philo->id);
	printf("%ld %d is eating\n", get_action_time(philo), philo->id);
	usleep(philo->time.time_to_eat);
	philo->time.current_time = get_current_time();
	release(philo);
	philo->eat_counter += 1;
}

static void	sleep_and_think(t_philo *philo)
{

	printf("%ld %d is sleeping\n", get_action_time(philo), philo->id);
	usleep(philo->time.time_to_sleep);
	printf("%ld %d is thinking\n", get_action_time(philo), philo->id);
}

static void	acquire(t_philo *philo)
{
	int	err;

	err = pthread_mutex_lock(philo->left_fork);
	if (err != 0)
		exit_func_call_err("pthread_mutex_lock", err);
	err = pthread_mutex_lock(philo->right_fork);
	if (err != 0)
		exit_func_call_err("pthread_mutex_lock", err);
}

static void	release(t_philo *philo)
{
	int	err;

	err = pthread_mutex_unlock(philo->left_fork);
	if (err != 0)
		exit_func_call_err("pthread_mutex_unlock", err);
	err = pthread_mutex_unlock(philo->right_fork);
	if (err != 0)
		exit_func_call_err("pthread_mutex_unlock", err);
}
