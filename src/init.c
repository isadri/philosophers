/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:53:25 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/09 18:00:42by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	set_time(t_philo **philos, char *argv[]);
//static void	fill_time_struct(t_time time, char *argv[]);
void	set_nbr_of_meals(t_philo *philo, char *arg, uint16_t nbr);
void	set_nbr_of_philos(t_philo *philo, uint16_t nbr);

int	philos_init(t_philo **philos, char *argv[])
{
	int				nbr_of_philos;

	nbr_of_philos = my_atoi(argv[1]);
	if (nbr_of_philos == 0)
		return (0);
	*philos = my_calloc(nbr_of_philos, sizeof(t_philo));
	set_nbr_of_meals(*philos, argv[5], nbr_of_philos);
	set_nbr_of_philos(*philos, nbr_of_philos);
	if (set_time(philos, argv) == 0)
		return (clear(philos), 0);
	if (mtx_init(philos, nbr_of_philos) == 0)
		return (free(philos), 0);
	return (1);
}

void	set_nbr_of_philos(t_philo *philo, uint16_t nbr)
{
	uint16_t	i;

	i = 0;
	while (i < nbr)
		philo[i++].nbr_of_philos = nbr;
}

void	set_nbr_of_meals(t_philo *philo, char *arg, uint16_t nbr)
{
	int			nbr_of_meals;
	uint16_t	i;

	nbr_of_meals = 0;
	if (arg == NULL)
		nbr_of_meals = -1;
	else
		nbr_of_meals = my_atoi(arg);
	i = 0;
	while (i < nbr)
	{
		philo[i].nbr_of_meals = nbr_of_meals;
		philo[i].meal = 0;
		i++;
	}
}

static int	set_time(t_philo **philos, char *argv[])
{
	uint16_t	i;

	i = 0;
	while (i < (*philos)->nbr_of_philos)
	{
		(*philos)[i].time.time_to_die = my_atoi(argv[2]);
		(*philos)[i].time.time_to_eat = my_atoi(argv[3]);
		(*philos)[i].time.time_to_sleep = my_atoi(argv[4]);
		(*philos)[i].time.last_eat_time = get_current_time();
		(*philos)[i].time.start_time = get_current_time();
		(*philos)[i].id = i + 1;
		i++;
	}
	return (1);
}
