/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:25:04 by lboulatr          #+#    #+#             */
/*   Updated: 2023/07/11 09:47:37 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static int	taking_forks(t_philo *philo);
static void	eating(t_philo *philo);
static void	sleeping(t_philo *philo);
static void	thinking(t_philo *philo);

void	ph_actions(t_philo *philo)
{
	if (taking_forks(philo) != SUCCESS)
		return ;
	eating(philo);
	sleeping(philo);
	thinking(philo);
}

static int	taking_forks(t_philo *philo)
{
	if (philo->id == philo->rules->n_philo)
	{
		if (philo->right_fork != NULL)
			pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	pthread_mutex_lock(&philo->rules->printing);
	ph_printing("has taken a fork.\n", philo);
	pthread_mutex_unlock(&philo->rules->printing);
	if (philo->right_fork == NULL)
	{
		ft_sleep(philo->rules->tt_die * 2);
		return (FAILURE);
	}
	pthread_mutex_lock(&philo->rules->printing);
	ph_printing("has taken a fork.\n", philo);
	pthread_mutex_unlock(&philo->rules->printing);
	return (SUCCESS);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->printing);
	ph_printing("is eating.\n", philo);
	pthread_mutex_unlock(&philo->rules->printing);
	pthread_mutex_lock(&philo->rules->check_meal);
	philo->last_meal = ph_get_actual_time();
	pthread_mutex_unlock(&philo->rules->check_meal);
	ft_sleep(philo->rules->tt_eat);
	if (philo->id == philo->rules->n_philo)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

static void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->printing);
	ph_printing("is sleeping.\n", philo);
	pthread_mutex_unlock(&philo->rules->printing);
	ft_sleep(philo->rules->tt_sleep);
}

static void	thinking(t_philo *philo)
{
	if (philo->rules->n_philo % 2 == 1)
		ft_sleep(philo->rules->tt_eat / 2);
	pthread_mutex_lock(&philo->rules->printing);
	ph_printing("is thinking.\n", philo);
	pthread_mutex_unlock(&philo->rules->printing);
}
