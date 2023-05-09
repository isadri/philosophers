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

static int	mtx_init(t_philo **philos, unsigned int nbr);
static int	forks_meal_mtx_init(t_philo **philos, pthread_mutex_t *forks_mtx);
static void	print_mtx_init(t_philo **philos, pthread_mutex_t *print_mtx);
static void	time_mtx_init(t_philo **philos, pthread_mutex_t *time_mtx);
static int	set_time(t_philo **philos, char *argv[]);
//static time_t	get_nbr_of_meals(char *arg);
void	set_nbr_of_meals(t_philo *philo, char *arg, unsigned int nbr);
void	set_nbr_of_philos(t_philo *philo, unsigned int nbr);

int	philos_init(t_philo **philos, char *argv[])
{
	int				nbr_of_philos;

	nbr_of_philos = my_atoi(argv[1]);
	*philos = my_calloc(nbr_of_philos, sizeof(t_philo));
	set_nbr_of_meals(*philos, argv[5], nbr_of_philos);
	set_nbr_of_philos(*philos, nbr_of_philos);
	if (set_time(philos, argv) == 0)
		return (clear(philos), 0);
	if (mtx_init(philos, nbr_of_philos) == 0)
		return (free(philos), 0);
	return (1);
}

void	set_nbr_of_philos(t_philo *philo, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr)
		philo[i++].nbr_of_philos = nbr;
}

void	set_nbr_of_meals(t_philo *philo, char *arg, unsigned int nbr)
{
	unsigned int	i;
	int	nbr_of_meals;

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

static int	mtx_init(t_philo **philos, unsigned int nbr)
{
	pthread_mutex_t	*forks_mtx;
	pthread_mutex_t	*print_mtx;
	pthread_mutex_t	*time_mtx;

	forks_mtx = my_calloc(nbr, sizeof(pthread_mutex_t));
	if (forks_mtx == NULL)
		return (0);
	print_mtx = my_calloc(1, sizeof(pthread_mutex_t));
	if (print_mtx == NULL)
		return (free(forks_mtx), 0);
	time_mtx = my_calloc(1, sizeof(pthread_mutex_t));
	if (time_mtx == NULL)
		return (free(forks_mtx), free(print_mtx), 0);
	if (forks_meal_mtx_init(philos, forks_mtx) == 0)
		return (0);
	print_mtx_init(philos, print_mtx);
	time_mtx_init(philos, time_mtx);
	return (1);
}

static int	forks_meal_mtx_init(t_philo **philos, pthread_mutex_t *forks_mtx)
{
	pthread_mutex_t	*meal_mtx;
	unsigned int	nbr;
	unsigned int	i;

	nbr = (*philos)->nbr_of_philos;
	meal_mtx = my_calloc(nbr, sizeof(pthread_mutex_t));
	if (meal_mtx == NULL)
		return (0);
	(*philos)->mtx.head_forks_mtx = forks_mtx;
	(*philos)->mtx.head_meal_mtx = meal_mtx;
	i = 0;
	while (i < nbr)
	{
		(*philos)[i].mtx.left_fork = &forks_mtx[i];
		(*philos)[i].mtx.right_fork = &forks_mtx[((i + 1) % nbr)];
		(*philos)[i].mtx.meal_mtx = &meal_mtx[i];
		i++;
	}
	return (1);
}

static void	print_mtx_init(t_philo **philos, pthread_mutex_t *print_mtx)
{
	unsigned int	nbr;
	unsigned int	i;

	nbr = (*philos)->nbr_of_philos;
	i = 0;
	while (i < nbr)
	{
		(*philos)[i].mtx.print_mtx = print_mtx;
		(*philos)[i].mtx.print_mtx = print_mtx;
		i++;
	}
}

static void	time_mtx_init(t_philo **philos, pthread_mutex_t *time_mtx)
{
	unsigned int	nbr;
	unsigned int	i;

	nbr = (*philos)->nbr_of_philos;
	i = 0;
	while (i < nbr)
	{
		(*philos)[i].mtx.time_mtx = time_mtx;
		(*philos)[i].mtx.time_mtx = time_mtx;
		i++;
	}
}

static int	set_time(t_philo **philos, char *argv[])
{
	unsigned int	i;

	i = 0;
	while (i < (*philos)->nbr_of_philos)
	{
		(*philos)[i].time.time_to_die = my_atoi(argv[2]) * 1000;
		(*philos)[i].time.time_to_eat = my_atoi(argv[3]) * 1000;
		(*philos)[i].time.time_to_sleep = my_atoi(argv[4]) * 1000;
		(*philos)[i].time.last_eat_time = 0;
		(*philos)[i].time.start_time = get_current_time();
		(*philos)[i].id = i + 1;
		i++;
	}
	return (1);
}
