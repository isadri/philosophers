/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_release.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:06:05 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/10 16:13:33 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	acquire(pthread_mutex_t *mtx)
{
	pthread_mutex_lock(mtx);
}

void	release(pthread_mutex_t *mtx)
{
	pthread_mutex_unlock(mtx);
}

void	acquire_forks(t_philo *philo)
{
	acquire(philo->mtx.left_fork);
	secure_print("has taken a fork", philo);
	acquire(philo->mtx.right_fork);
	secure_print("has taken a fork", philo);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->mtx.left_fork);
	pthread_mutex_unlock(philo->mtx.right_fork);
}
