/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:44:45 by lboulatr          #+#    #+#             */
/*   Updated: 2023/06/28 08:40:22 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	ph_end(t_ph *ph)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ph->rules.n_philo)
	{
		pthread_join(ph->philo[i].thread, NULL);
		i++;
	}
	while (j < ph->rules.n_philo)
	{
		pthread_mutex_destroy(&ph->philo[j].left_fork);
		j++;
	}
	pthread_mutex_destroy(&ph->rules.printing);
	pthread_mutex_destroy(&ph->rules.check_meal);
	pthread_mutex_destroy(&ph->rules.mutex_count);
	pthread_mutex_destroy(&ph->rules.mutex_one_dead);
	pthread_mutex_destroy(&ph->rules.mutex_status);
	free(ph->philo);
}
