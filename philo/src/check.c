/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:52:26 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/17 11:57:31 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static bool	is_valid_number(char *arg);

int	check_arguments(char *argv[])
{
	char	*args[5];
	int		i;

	args[0] = "number_of_philosopher";
	args[1] = "time_to_die";
	args[2] = "time_to_eat";
	args[3] = "time_to_sleep";
	args[4] = "number_of_times_each_philosopher_must_eat";
	i = -1;
	while (argv[++i])
	{
		if (is_valid_number(argv[i]) == false)
			return (invalid_arg(argv[i], args[i]), EOF);
	}
	return (OK);
}

static bool	is_valid_number(char *arg)
{
	if (*arg == '\0')
		return (false);
	while (*arg && is_digit(*arg))
		arg++;
	return (*arg == '\0');
}

void	dead_print(t_philo *philo)
{
	acquire(philo->mtx.print_mtx);
	printf("%ld %u has died\n", calculate_time(philo->time.start_time),
		philo->id);
}
