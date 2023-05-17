/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:06:52 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/17 11:57:05 by iabkadri         ###   ########.fr       */
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
		if (philo_is_dead(&philos[i]))
			return (dead_print(&philos[i]), false);
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
	if (philo->nbr_of_meals == -1)
		return (false);
	acquire(philo->mtx.meal_mtx);
	if (philo->meal < philo->nbr_of_meals)
		return (release(philo->mtx.meal_mtx), false);
	release(philo->mtx.meal_mtx);
	return (true);
}

bool	philo_is_dead(t_philo *philo)
{
	acquire(philo->mtx.time_mtx);
	if (get_current_time() - philo->time.last_eat_time
		>= philo->time.time_to_die)
		return (release(philo->mtx.time_mtx), true);
	release(philo->mtx.time_mtx);
	return (false);
}
