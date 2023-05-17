/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:52:15 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/17 12:03:20 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char *argv[])
{
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (usage_err(), 1);
	if (check_arguments(argv + 1) == EOF)
		return (2);
	if (philos_init(&philos, argv) == 0)
		return (3);
	if (philos->nbr_of_meals == 0)
		return (clear(&philos), 0);
	if (launch(philos) == 0)
		return (clear(&philos), 4);
	clear(&philos);
	return (0);
}
