/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:06:52 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/11 08:42:14 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static bool	secure_time_check(t_philo *philos);
static bool	secure_meals_check(t_philo *philos);

void	monitor(t_philo *philos)
{
	while (secure_time_check(philos) && secure_meals_check(philos))
		;
}

static bool	secure_time_check(t_philo *philos)
{
	uint16_t	i;
	uint16_t	nbr_of_philos;

	nbr_of_philos = philos->nbr_of_philos;
	i = 0;
	while (i < nbr_of_philos)
	{
		my_usleep(10);
		if (philo_is_dead(&philos[i]))
			return (secure_print("died", &philos[i]), false);
		i++;
	}
	return (true);
}

static bool	secure_meals_check(t_philo *philos)
{
	uint16_t	nbr_of_philos;
	uint16_t	i;

	nbr_of_philos = philos->nbr_of_philos;
	i = 0;
	while (i < nbr_of_philos)
	{
		if (philo_eats_all_meals(&philos[i]) == false)
			return (true);
		i++;
	}
	return (false);
}

bool	philo_eats_all_meals(t_philo *philo)
{
	bool	val;

	if (philo->nbr_of_meals == -1)
		return (false);
	val = 1;
	pthread_mutex_lock(philo->mtx.meal_mtx);
	if (philo->meal < philo->nbr_of_meals)
		val = 0;
	pthread_mutex_unlock(philo->mtx.meal_mtx);
	return (val);
}

bool	philo_is_dead(t_philo *philo)
{
	bool	val;

	val = 0;
	pthread_mutex_lock(philo->mtx.time_mtx);
	if (get_current_time() - philo->time.last_eat_time
		>= philo->time.time_to_die)
		val = 1;
	pthread_mutex_unlock(philo->mtx.time_mtx);
	return (val);
}
