/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:51:39 by lboulatr          #+#    #+#             */
/*   Updated: 2023/07/11 08:37:27 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static void	dead(t_ph *ph, int i);
static void	change_status(t_ph *ph);

void	ph_check_death(t_ph *ph, int i)
{
	while (1)
	{
		i = -1;
		while (++i < ph->rules.n_philo && (ph->rules.one_dead == FALSE))
		{
			pthread_mutex_lock(&(ph->rules.check_meal));
			if ((ph_get_actual_time() - \
				ph->philo[i].last_meal >= (ph->rules.tt_die)))
				dead(ph, i);
			pthread_mutex_unlock(&(ph->rules.check_meal));
		}
		i = 0;
		if (ph->rules.one_dead == TRUE)
			break ;
		pthread_mutex_lock(&ph->rules.mutex_count);
		while (ph->rules.must_eat != -1 && \
				ph->philo[i].count_eat >= ph->rules.must_eat)
			i++;
		pthread_mutex_unlock(&ph->rules.mutex_count);
		if (i == ph->rules.must_eat)
		{
			change_status(ph);
			break ;
		}
	}
}

static void	dead(t_ph *ph, int i)
{
	pthread_mutex_lock(&ph->philo[i].rules->printing);
	ph_printing("died.\n", &ph->philo[i]);
	pthread_mutex_unlock(&ph->philo[i].rules->printing);
	pthread_mutex_lock(&ph->rules.mutex_one_dead);
	ph->rules.one_dead = TRUE;
	pthread_mutex_unlock(&ph->rules.mutex_one_dead);
}

static void	change_status(t_ph *ph)
{
	pthread_mutex_lock(&ph->rules.mutex_status);
	ph->rules.status_all = TRUE;
	pthread_mutex_unlock(&ph->rules.mutex_status);
}
