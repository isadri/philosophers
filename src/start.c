/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:59:17 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/10 16:50:28 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	eat_think_sleep(t_philo *philo);

void	*start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		eat_think_sleep(philo);
		if (philo_eats_all_meals(philo) || philo_is_dead(philo))
			return (NULL);
	}
}

static void	eat_think_sleep(t_philo *philo)
{
	acquire_forks(philo);
	update_last_eat_time(philo);
	secure_print("is eating", philo);
	my_usleep(philo->time.time_to_eat);
	increase_meal_counter(philo);
	release_forks(philo);
	secure_print("is sleeping", philo);
	my_usleep(philo->time.time_to_sleep);
	secure_print("is thinking", philo);
}

void	update_last_eat_time(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx.time_mtx);
	philo->time.last_eat_time = get_current_time();
	pthread_mutex_unlock(philo->mtx.time_mtx);
}

void	increase_meal_counter(t_philo *philo)
{
	acquire(philo->mtx.meal_mtx);
	philo->meal++;
	release(philo->mtx.meal_mtx);
}

void	secure_print(char *msg, t_philo *philo)
{
	acquire(philo->mtx.print_mtx);
	printf("%ld %u %s\n", calculate_time(philo->time.start_time),
		philo->id, msg);
	release(philo->mtx.print_mtx);
}
