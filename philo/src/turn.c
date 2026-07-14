/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enmanueliglesiasgarciadelcastillo <enma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:35:00 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/07/14 16:38:28 by enmanueligl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_turn(t_philo *philo)
{
	long long	elapsed;

	elapsed = get_time_ms() - philo->data->born_time;
	return (elapsed / philo->data->time_to_eat + 1);
}

int	one_philo(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->r_fork) != 0)
		return (1);
	if (print_action(philo, " has taken right fork"))
		return (pthread_mutex_unlock(&philo->r_fork), 1);
	ft_msleep(philo, philo->data->time_to_die);
	if (pthread_mutex_unlock(&philo->r_fork) != 0)
		return (1);
	return (1);
}

int	same_turn(t_philo *philo, int turn)
{
	if (philo->last_turn != turn)
		return (0);
	usleep(500);
	return (1);
}

int	should_eat(t_philo *philo, int turn)
{
	if (philo->data->num_philos % 2 == 0)
		return (turn % 2 == philo->id % 2);
	return (((turn + (philo->data->num_philos * 2)) - (2 + philo->id))
		% philo->data->num_philos != 0);
}
