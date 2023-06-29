/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:37:40 by lboulatr          #+#    #+#             */
/*   Updated: 2023/06/27 15:15:41 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	ph_printing(char *msg, t_philo *philo)
{
	long long		time;

	time = 0;
	time = ph_get_actual_time() - philo->rules->start;
	pthread_mutex_lock(&philo->rules->mutex_one_dead);
	pthread_mutex_lock(&philo->rules->mutex_status);
	if (time >= 0 && philo->rules->status_all != TRUE \
			&& philo->rules->one_dead != TRUE)
		printf("% lld %d %s", time, philo->id, msg);
	pthread_mutex_unlock(&philo->rules->mutex_one_dead);
	pthread_mutex_unlock(&philo->rules->mutex_status);
}
