/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:49:01 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/10 16:43:55 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	create_philos(t_philo *philo);
static int	detach_philos(t_philo *philo);

int	launch(t_philo *philos)
{
	if (create_philos(philos) == 0)
		return (0);
	if (detach_philos(philos) == 0)
		return (0);
	monitor(philos);
	destroy_mutexes(philos);
	return (1);
}

static int	create_philos(t_philo *philos)
{
	uint16_t	i;
	uint16_t	nbr;

	nbr = philos->nbr_of_philos;
	i = 0;
	while (i < nbr)
	{
		if (pthread_create(&philos[i].ph, NULL, start, &philos[i]))
			return (0);
		if ((i + 1) % 2 != 0)
			usleep(60);
		i++;
	}
	return (1);
}

static int	detach_philos(t_philo *philos)
{
	uint16_t	i;
	uint16_t	nbr;

	nbr = philos->nbr_of_philos;
	i = 0;
	while (i < nbr)
	{
		if (pthread_detach(philos[i].ph) != 0)
			return (0);
		i++;
	}
	return (1);
}

time_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

time_t	calculate_time(time_t start_time)
{
	return (get_current_time() - start_time);
}
