/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osterger <osterger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:40:11 by osterger          #+#    #+#             */
/*   Updated: 2023/06/25 07:36:08 by osterger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	x;
	int			sign;

	i = 0;
	x = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (x != (((x * 10) + (str[i] - 48)) / 10))
			return (((sign + 1) / -2));
		x = (str[i] - 48) + (x * 10);
		i++;
	}
	x = x * sign;
	return ((int)x);
}

void	ft_sleep(long long time)
{
	long long	start;

	start = 0;
	start = ph_get_actual_time();
	while ((ph_get_actual_time() - start) < time)
		usleep(time / 10);
}

void	ph_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(FAILURE);
}
