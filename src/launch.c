/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:49:01 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/09 21:34:49 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	create_philo(t_philo *philo);
static int	detach_philo(t_philo *philo);

int	launch(t_philo *philo)
{
	if (create_philo(philo) == 0)
		return (0);
	if (detach_philo(philo) == 0)
		return (0);
	while (true);
}

static int	create_philo(t_philo *philo)
{
	unsigned int	i;
	unsigned int	nbr;

	nbr = philo->nbr_of_philos;
	i = 0;
	while (i < nbr)
	{
		if ((i % 1) % nbr != 0)
			usleep(40);
		if (pthread_create(&philo[i].ph, NULL, start, &philo[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	detach_philo(t_philo *philo)
{
	unsigned int	i;
	unsigned int	nbr;

	nbr = philo->nbr_of_philos;
	i = 0;
	while (i < nbr)
	{
		if (pthread_detach(philo[i].ph) != 0)
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
