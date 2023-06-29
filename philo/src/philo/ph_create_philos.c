/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:02:01 by osterger          #+#    #+#             */
/*   Updated: 2023/06/27 15:12:14 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static int	init_mutex(t_ph *ph);

int	ph_create_philos(t_ph *ph)
{
	int	i;

	i = 0;
	init_mutex(ph);
	ph->philo = malloc(sizeof(t_philo) * ph->rules.n_philo);
	if (!ph->philo)
		return (FAILURE);
	while (i < ph->rules.n_philo)
	{
		ph->philo[i].id = i + 1;
		ph->philo[i].count_eat = 0;
		ph->philo[i].end = 0;
		ph->philo[i].start = ph->rules.start;
		ph->philo[i].right_fork = NULL;
		if (pthread_mutex_init(&ph->philo[i].left_fork, NULL) != 0)
			return (FAILURE);
		if (ph->rules.n_philo == 1)
			return (SUCCESS);
		if (i == ph->rules.n_philo - 1)
			ph->philo[i].right_fork = &ph->philo[0].left_fork;
		else
			ph->philo[i].right_fork = &ph->philo[i + 1].left_fork;
		i++;
	}
	return (SUCCESS);
}

static int	init_mutex(t_ph *ph)
{
	if (pthread_mutex_init(&ph->rules.printing, NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&ph->rules.check_meal, NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&ph->rules.mutex_count, NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&ph->rules.mutex_one_dead, NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&ph->rules.mutex_status, NULL) != 0)
		return (FAILURE);
	return (SUCCESS);
}
