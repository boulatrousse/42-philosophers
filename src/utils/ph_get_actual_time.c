/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_get_actual_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:24:29 by osterger          #+#    #+#             */
/*   Updated: 2023/06/25 07:34:44 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

long long	ph_get_actual_time(void)
{
	struct timeval		current_time;
	long long			time;

	time = 0;
	if (gettimeofday(&current_time, NULL) != 0)
		return (FAILURE);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}
