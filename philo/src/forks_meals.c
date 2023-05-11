/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_meals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:30:01 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/10 16:59:28 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	set_forks_meals_mtx(t_philo **philos, pthread_mutex_t *forks_mtx,
			pthread_mutex_t *meals_mtx);

int	forks_meals_mtx_init(t_philo **philos, pthread_mutex_t *forks_mtx)
{
	pthread_mutex_t	*meals_mtx;
	uint16_t		nbr;

	nbr = (*philos)->nbr_of_philos;
	meals_mtx = my_calloc(nbr, sizeof(pthread_mutex_t));
	if (meals_mtx == NULL)
		return (0);
	initialize_mtx(meals_mtx, nbr);
	(*philos)->mtx.head_forks_mtx = forks_mtx;
	(*philos)->mtx.head_meals_mtx = meals_mtx;
	set_forks_meals_mtx(philos, forks_mtx, meals_mtx);
	return (1);
}

void	set_forks_meals_mtx(t_philo **philos, pthread_mutex_t *forks_mtx,
	pthread_mutex_t *meals_mtx)
{
	uint16_t	i;
	uint16_t	nbr_of_philos;

	nbr_of_philos = (*philos)->nbr_of_philos;
	i = 0;
	while (i < nbr_of_philos)
	{
		(*philos)[i].mtx.left_fork = &forks_mtx[i];
		(*philos)[i].mtx.right_fork = &forks_mtx[(i + 1) % nbr_of_philos];
		(*philos)[i].mtx.meal_mtx = &meals_mtx[i];
		i++;
	}
}

void	print_mtx_init(t_philo **philos, pthread_mutex_t *print_mtx)
{
	uint16_t	nbr;
	uint16_t	i;

	nbr = (*philos)->nbr_of_philos;
	initialize_mtx(print_mtx, 1);
	i = 0;
	while (i < nbr)
		(*philos)[i++].mtx.print_mtx = print_mtx;
}

void	time_mtx_init(t_philo **philos, pthread_mutex_t *time_mtx)
{
	uint16_t	nbr;
	uint16_t	i;

	nbr = (*philos)->nbr_of_philos;
	initialize_mtx(time_mtx, 1);
	i = 0;
	while (i < nbr)
		(*philos)[i++].mtx.time_mtx = time_mtx;
}
