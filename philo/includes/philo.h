/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiglesia <eiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:31:40 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/07/13 21:07:56 by eiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	struct s_data	*data;
	pthread_t		thread;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	long long		born_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				num_philos;
}	t_data;

void	print_action(t_philo *philo, char *action);
void	*day(void *arg);
int		parseo(int argc, char **argv);

// utils

int		ft_atoi(const char *nptr);

#endif
