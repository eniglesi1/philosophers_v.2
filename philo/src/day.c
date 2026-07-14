/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enmanueliglesiasgarciadelcastillo <enma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:31:50 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/07/14 15:26:24 by enmanueligl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	unlock_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->r_fork) != 0)
		return (1);
	if (pthread_mutex_unlock(philo->l_fork) != 0)
		return (1);
	return (0);
}

static int	check_meals(t_philo *philo)
{
	t_philo	*philos;
	int		i;
	int		done;

	if (philo->data->num_meals == -1)
		return (0);
	philos = philo - (philo->id - 1);
	i = 0;
	if (pthread_mutex_lock(&philo->data->dead) != 0)
		return (1);
	philo->meals++;
	while (i < philo->data->num_philos
		&& philos[i].meals >= philo->data->num_meals)
		i++;
	if (i == philo->data->num_philos)
		philo->data->greaper = 1;
	done = philo->data->greaper;
	if (pthread_mutex_unlock(&philo->data->dead) != 0)
		return (1);
	return (done);
}

static int	eat_turn(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->r_fork) != 0)
		return (1);
	if (print_action(philo, " has taken right fork"))
		return (pthread_mutex_unlock(&philo->r_fork), 1);
	if (pthread_mutex_lock(philo->l_fork) != 0)
		return (pthread_mutex_unlock(&philo->r_fork), 1);
	if (print_action(philo, " has taken left fork"))
		return (unlock_forks(philo), 1);
	philo->last_meal = get_time_ms();
	if (print_action(philo, " is eating")
		|| ft_msleep(philo, philo->data->time_to_eat))
		return (unlock_forks(philo), 1);
	if (unlock_forks(philo))
		return (1);
	if (check_meals(philo))
		return (1);
	philo->hungry = 0;
	if (print_action(philo, " is sleeping"))
		return (1);
	if (ft_msleep(philo, philo->data->time_to_sleep))
		return (1);
	return (print_action(philo, " is thinking"));
}

static int	do_turn(t_philo *philo, int turn)
{
	if (philo->hungry == 0)
	{
		philo->hungry = 1;
		if (philo->last_turn == 0)
			philo->last_turn = turn;
		return (0);
	}
	philo->last_turn = turn;
	if (should_eat(philo, turn))
		return (eat_turn(philo));
	return (ft_msleep(philo, philo->data->time_to_eat));
}

void	*day(void *arg)
{
	t_philo	*philo;
	int		turn;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
		return (one_philo(philo), NULL);
	while (1)
	{
		turn = get_turn(philo);
		if (same_turn(philo, turn))
			continue ;
		if (do_turn(philo, turn))
			return (NULL);
	}
	return (NULL);
}
