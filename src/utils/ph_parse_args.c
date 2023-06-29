/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 07:46:23 by osterger          #+#    #+#             */
/*   Updated: 2023/06/23 02:12:26 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static int	check_arg(char **arg);
static int	is_digit(char *arg);

int	ph_parse_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (FAILURE);
	if (check_arg(argv) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static int	check_arg(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (is_digit(arg[i]) != SUCCESS)
			return (FAILURE);
		if (ft_atoi(arg[i]) > 2147483647)
			return (FAILURE);
		if (ft_atoi(arg[i]) <= 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	is_digit(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (FAILURE);
	}
	return (SUCCESS);
}
