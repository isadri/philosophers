/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:52:30 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/10 16:52:31 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	usage_err(void)
{
	printf(USG_ERR_MSG " number_of_philosophers time_to_die time_to_eat "
		"time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}

void	invalid_arg(char *arg, char *expected_arg)
{
	printf(INVALID_ARG_MSG " '%s' for %s\n", arg, expected_arg);
}

void	exit_func_call_err(char *func_name, int err)
{
	printf("%s: %s\n", func_name, strerror(err));
	exit(EXIT_FAILURE);
}
