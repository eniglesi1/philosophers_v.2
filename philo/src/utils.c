/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiglesia <eiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:40:00 by eiglesia          #+#    #+#             */
/*   Updated: 2026/07/14 13:40:00 by eiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

int	print_action(t_philo *philo, char *str)
{
	if (pthread_mutex_lock(&philo->data->print) != 0)
		return (1);
	if (pthread_mutex_lock(&philo->data->dead) != 0)
		return (pthread_mutex_unlock(&philo->data->print), 1);
	if (philo->data->greaper == 1)
	{
		if (pthread_mutex_unlock(&philo->data->dead) != 0)
			return (1);
		if (pthread_mutex_unlock(&philo->data->print) != 0)
			return (1);
		return (1);
	}
	if (pthread_mutex_unlock(&philo->data->dead) != 0)
		return (pthread_mutex_unlock(&philo->data->print), 1);
	printf("%lld %d %s\n", get_time_ms() - philo->data->born_time,
		philo->id, str);
	if (pthread_mutex_unlock(&philo->data->print) != 0)
		return (1);
	return (0);
}

static int	kill_philo(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->print) != 0)
		return (1);
	if (pthread_mutex_lock(&philo->data->dead) != 0)
		return (pthread_mutex_unlock(&philo->data->print), 1);
	if (philo->data->greaper == 0)
	{
		printf("%lld %d died\n", philo->last_meal + philo->data->time_to_die
			- philo->data->born_time, philo->id);
		philo->data->greaper = 1;
	}
	if (pthread_mutex_unlock(&philo->data->dead) != 0)
		return (1);
	if (pthread_mutex_unlock(&philo->data->print) != 0)
		return (1);
	return (1);
}

int	ft_msleep(t_philo *philo, int time)
{
	long long	end;
	long long	time_to_death;

	end = get_time_ms() + time;
	while (get_time_ms() < end)
	{
		time_to_death = philo->data->time_to_die - (get_time_ms()
				- philo->last_meal);
		if (time_to_death <= 0)
			return (kill_philo(philo));
		if (time_to_death < 2)
			usleep(time_to_death * 1000);
		else
			usleep(500);
	}
	if (get_time_ms() - philo->last_meal >= philo->data->time_to_die)
		return (kill_philo(philo));
	return (0);
}
