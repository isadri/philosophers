/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:36:40 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/10 16:49:00 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	mtx_init(t_philo **philos, uint16_t nbr)
{
	pthread_mutex_t	*forks_mtx;
	pthread_mutex_t	*print_mtx;
	pthread_mutex_t	*time_mtx;

	forks_mtx = get_forks_mtx(nbr);
	if (forks_mtx == NULL)
		return (0);
	print_mtx = get_mtx();
	if (print_mtx == NULL)
		return (clear_forks_mtx(forks_mtx, nbr), 0);
	time_mtx = get_mtx();
	if (time_mtx == NULL)
		return (clear_mtx(print_mtx), clear_forks_mtx(forks_mtx, nbr), 0);
	if (forks_meals_mtx_init(philos, forks_mtx) == 0)
		return (clear_forks_mtx(forks_mtx, nbr), clear_mtx(print_mtx),
			clear_mtx(time_mtx), 0);
	print_mtx_init(philos, print_mtx);
	time_mtx_init(philos, time_mtx);
	return (1);
}

pthread_mutex_t	*get_forks_mtx(uint16_t nbr)
{
	pthread_mutex_t	*forks_mtx;
	uint16_t	i;

	forks_mtx = my_calloc(nbr, sizeof(pthread_mutex_t));
	if (forks_mtx == NULL)
		return (NULL);
	i = 0;
	while (i < nbr)
		pthread_mutex_init(&forks_mtx[i++], NULL);
	return (forks_mtx);
}

pthread_mutex_t	*get_mtx(void)
{
	pthread_mutex_t	*mtx;

	mtx = my_calloc(1, sizeof(pthread_mutex_t));
	if (mtx == NULL)
		return (NULL);
	pthread_mutex_init(mtx, NULL);
	return (mtx);
}

void	initialize_mtx(pthread_mutex_t *mtx, uint16_t nbr)
{
	uint16_t	i;

	i = 0;
	while (i < nbr)
		pthread_mutex_init(&mtx[i++], NULL);
}
