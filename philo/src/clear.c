/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:54:27 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/10 16:54:28 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	clear(t_philo **philos)
{
	clear_forks_mtx((*philos)->mtx.head_forks_mtx, (*philos)->nbr_of_philos);
	free((*philos)->mtx.head_meals_mtx);
	free((*philos)->mtx.print_mtx);
	free((*philos)->mtx.time_mtx);
	free(*philos);
}

void	clear_forks_mtx(pthread_mutex_t *forks_mtx, uint16_t nbr)
{
	uint16_t	i;

	i = 0;
	while (i < nbr)
		pthread_mutex_destroy(&forks_mtx[i++]);
	free(forks_mtx);
}

void	clear_mtx(pthread_mutex_t *mtx)
{
	pthread_mutex_destroy(mtx);
	free(mtx);
}
