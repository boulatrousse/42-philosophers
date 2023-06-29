/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:15:53 by osterger          #+#    #+#             */
/*   Updated: 2023/06/26 13:38:05 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

int	ph_init(int argc, char **argv, t_ph *ph)
{
	if (ph_parse_args(argc, argv) != SUCCESS)
		return (FAILURE);
	ph->rules.n_philo = ft_atoi(argv[1]);
	if (ph->rules.n_philo <= 0)
		return (FAILURE);
	ph->rules.tt_die = ft_atoi(argv[2]);
	ph->rules.tt_eat = ft_atoi(argv[3]);
	ph->rules.tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ph->rules.must_eat = ft_atoi(argv[5]);
	else
		ph->rules.must_eat = -1;
	ph->rules.count_all = 0;
	ph->rules.status_all = FALSE;
	ph->rules.one_dead = FALSE;
	ph->rules.start = ph_get_actual_time();
	if (ph->rules.start == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
