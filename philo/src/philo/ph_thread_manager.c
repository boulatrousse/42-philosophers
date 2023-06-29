/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 03:26:21 by osterger          #+#    #+#             */
/*   Updated: 2023/06/29 08:06:50 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static void	*ph_thread(void *arg_philo);
static int	check_death_status(t_philo *philo);
static void	change_status(t_philo *philo);

int	ph_thread_manager(t_ph *ph)
{
	int	i;

	i = 0;
	while (i < ph->rules.n_philo)
	{
		ph->philo[i].rules = &ph->rules;
		if (pthread_create(&ph->philo[i].thread, NULL, \
					ph_thread, &ph->philo[i]) != 0)
			return (FAILURE);
		{
			pthread_mutex_lock(&ph->rules.check_meal);
			ph->philo[i].last_meal = ph_get_actual_time();
			pthread_mutex_unlock(&ph->rules.check_meal);
		}
		i++;
	}
	ph_check_death(ph, 0);
	ph_end(ph);
	return (SUCCESS);
}

static void	*ph_thread(void *arg_philo)
{
	t_philo	*philo;

	philo = (t_philo *)arg_philo;
	if (philo->id % 2 == 0)
		ft_sleep(philo->rules->tt_sleep);
	while (check_death_status(philo) != FAILURE)
	{
		ph_actions(philo);
		pthread_mutex_lock(&philo->rules->mutex_count);
		philo->count_eat++;
		pthread_mutex_unlock(&philo->rules->mutex_count);
		if (philo->count_eat == philo->rules->must_eat)
		{
			pthread_mutex_lock(&philo->rules->mutex_count);
			philo->rules->count_all++;
			if (philo->rules->count_all == philo->rules->n_philo)
			{
				change_status(philo);
				pthread_mutex_unlock(&philo->rules->mutex_count);
				return (NULL);
			}
			pthread_mutex_unlock(&philo->rules->mutex_count);
		}
	}
	return (NULL);
}

static int	check_death_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->mutex_one_dead);
	pthread_mutex_lock(&philo->rules->mutex_status);
	if (philo->rules->one_dead == FALSE && philo->rules->status_all != TRUE)
	{
		pthread_mutex_unlock(&philo->rules->mutex_one_dead);
		pthread_mutex_unlock(&philo->rules->mutex_status);
		return (SUCCESS);
	}
	pthread_mutex_unlock(&philo->rules->mutex_one_dead);
	pthread_mutex_unlock(&philo->rules->mutex_status);
	return (FAILURE);
}

static void	change_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->mutex_status);
	philo->rules->status_all = TRUE;
	pthread_mutex_unlock(&philo->rules->mutex_status);
}
