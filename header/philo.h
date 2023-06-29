/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 07:35:24 by osterger          #+#    #+#             */
/*   Updated: 2023/06/29 08:05:53 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>

# define SUCCESS    EXIT_SUCCESS
# define FAILURE    EXIT_FAILURE
# define TRUE		EXIT_SUCCESS
# define FALSE		EXIT_FAILURE
# define CHECK 		0
# define ONE_DEAD	1
# define ALL_EAT 	2

typedef struct s_rules
{
	int					n_philo;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					must_eat;
	int					count_all;
	int					status_all;
	int					one_dead;

	long long			start;
	pthread_mutex_t		printing;
	pthread_mutex_t		check_meal;
	pthread_mutex_t		mutex_count;
	pthread_mutex_t		mutex_one_dead;
	pthread_mutex_t		mutex_status;
}				t_rules;

typedef struct s_philo
{
	int					id;
	int					count_eat;
	int					end;

	long long			start;
	long long			last_meal;
	pthread_t			thread;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;

	t_rules				*rules;
}					t_philo;

typedef struct s_ph
{
	t_philo			*philo;
	t_rules			rules;
}				t_ph;

//---------------------- UTILS ---------------------------------

int				ft_atoi(const char *str);
void			ft_putstr_fd(char *s, int fd);
void			ft_sleep(long long time);
void			ph_exit(char *msg);
int				ph_parse_args(int argc, char **argv);
long long		ph_get_actual_time(void);

//---------------------- PHILO ---------------------------------

int				ph_init(int argc, char **argv, t_ph *ph);
int				ph_create_philos(t_ph *ph);
int				ph_thread_manager(t_ph *ph);
int				ph_actions(t_philo *philo);
void			ph_printing(char *msg, t_philo *philo);
void			ph_check_death(t_ph *ph, int i);
void			ph_end(t_ph *ph);

#endif
