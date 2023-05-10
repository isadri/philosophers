/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:04:18 by iabkadri          #+#    #+#             */
/*   Updated: 2023/05/10 16:04:27 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	my_usleep(time_t time_to_sleep)
{
	time_t	end_time;

	end_time = get_current_time() + time_to_sleep;
	while (get_current_time() < end_time)
		usleep(100);
}
