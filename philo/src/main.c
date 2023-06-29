/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 07:41:49 by osterger          #+#    #+#             */
/*   Updated: 2023/06/29 14:42:45 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_ph	ph;

	if (ph_init(argc, argv, &ph) != SUCCESS)
		ph_exit("Arguments error.\n");
	if (ph_create_philos(&ph, 0) != SUCCESS)
		ph_exit("Error during the creation of philos.\n");
	if (ph_thread_manager(&ph) != SUCCESS)
		ph_exit("Error with the threads.\n");
	return (SUCCESS);
}
