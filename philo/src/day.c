/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enmanueliglesiasgarciadelcastillo <enma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:31:50 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/07/13 17:30:31 by enmanueligl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(t_philo *philo, char *str)
{
	printf("%s", str);
	printf("\n %d", philo->id);
}


void	*day(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	print_action(philo, " has taken rigth fork");
	print_action(philo, " has taken left fork");
	print_action(philo, " is eating");
	print_action(philo, " is sleaping");
	print_action(philo, " is thinking");
	return (NULL);
}
