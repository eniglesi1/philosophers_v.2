/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enmanueliglesiasgarciadelcastillo <enma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:31:40 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/06/02 20:54:49 by enmanueligl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "ft_printf2.0/ft_printf.h"


typedef struct s_philo
{
	int				id;
	struct s_times	*times;
	pthread_t		thread;
}	t_philo;

typedef struct s_times
{
	long long		born_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
}	t_times;

void	print_action(t_philo *philo, char *action);
void	*day(void *arg);

#endif

