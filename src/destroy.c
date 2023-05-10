/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:06:58 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/10 16:46:38 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	destroy_forks_mtx(pthread_mutex_t *forks_mtx, uint16_t nbr);
static void	destroy_meals_mtx(pthread_mutex_t *meals_mtx, uint16_t nbr);

void	destroy_mutexes(t_philo *philos)
{
	uint16_t	nbr_of_philos;
	uint16_t	i;

	nbr_of_philos = philos->nbr_of_philos;
	destroy_forks_mtx(philos->mtx.head_forks_mtx, nbr_of_philos);
	destroy_meals_mtx(philos->mtx.head_meals_mtx, nbr_of_philos);
	i = 0;
	while (i < nbr_of_philos)
	{
		pthread_mutex_destroy(philos[i].mtx.print_mtx);
		pthread_mutex_destroy(philos[i].mtx.time_mtx);
		i++;
	}
}

static void	destroy_forks_mtx(pthread_mutex_t *forks_mtx, uint16_t nbr)
{
	uint16_t	i;

	i = 0;
	while (i < nbr)
		pthread_mutex_destroy(&forks_mtx[i++]);
}

static void	destroy_meals_mtx(pthread_mutex_t *meals_mtx, uint16_t nbr)
{
	uint16_t	i;

	i = 0;
	while (i < nbr)
		pthread_mutex_destroy(&meals_mtx[i++]);
}
