/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:59:17 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/09 21:14:33 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	eat_think_sleep(t_philo *philo);
static void	acquire(t_philo *philo);
static void	release(t_philo *philo);
void		secure_print(char *msg, t_philo *philo);
bool		eat_nbr_of_meals(t_philo *philo);

void	*start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		eat_think_sleep(philo);
		if (eat_nbr_of_meals(philo))
			return (NULL);
	}
}

static void	eat_think_sleep(t_philo *philo)
{
	acquire(philo);
	secure_print("is eating", philo);
	usleep(philo->time.time_to_eat);
	increase_meal_counter(philo);
	release(philo);
	secure_print("is sleeping", philo);
	usleep(philo->time.time_to_sleep);
	secure_print("is thinking", philo);
}

void	increase_meal_counter(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx.meal_mtx);
	philo->meal++;
	pthread_mutex_unlock(philo->mtx.meal_mtx);
}

static void	acquire(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx.left_fork);
	secure_print("has taken a fork", philo);
	pthread_mutex_lock(philo->mtx.right_fork);
	secure_print("has taken a fork", philo);
	pthread_mutex_unlock(philo->mtx.left_fork);
	pthread_mutex_unlock(philo->mtx.right_fork);
}

static void	release(t_philo *philo)
{
	pthread_mutex_unlock(philo->mtx.left_fork);
	pthread_mutex_unlock(philo->mtx.right_fork);
}

void	secure_print(char *msg, t_philo *philo)
{
	pthread_mutex_lock(philo->mtx.print_mtx);
	printf("%ld %u %s\n", calculate_time(philo->time.start_time),
		philo->id, msg);
	pthread_mutex_unlock(philo->mtx.print_mtx);
}

bool	eat_nbr_of_meals(t_philo *philo)
{
	bool	equal;

	equal = 0;
	pthread_mutex_lock(philo->mtx.meal_mtx);
	if (philo->meal == philo->nbr_of_meals)
		equal = 1;
	pthread_mutex_unlock(philo->mtx.meal_mtx);
	return (equal);
}
