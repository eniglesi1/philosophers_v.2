/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enmanueliglesiasgarciadelcastillo <enma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:31:40 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/07/14 13:33:04 by enmanueligl      ###   ########.fr       */
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
	long long		last_meal;
	int				hungry;
	int				meals;
	int				last_turn;
}	t_philo;

typedef struct s_data
{
	long long		born_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				num_philos;
	int				greaper;
	pthread_mutex_t	dead;
	pthread_mutex_t	print;
}	t_data;

int			print_action(t_philo *philo, char *action);
void		*day(void *arg);
int			parseo(int argc, char **argv);
long long	get_time_ms(void);
int			ft_atoi(const char *nptr);
int			ft_msleep(t_philo *philo, int time);
int			get_turn(t_philo *philo);
int			one_philo(t_philo *philo);
int			same_turn(t_philo *philo, int turn);
int			should_eat(t_philo *philo, int turn);

#endif
