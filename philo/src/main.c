/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enmanueliglesiasgarciadelcastillo <enma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:31:43 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/07/13 18:54:04 by enmanueligl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_times		*times;

	if (parseo(argc, argv) == 1)
	{
		times = get_times(argc, argv);
		philo = get_philo(argc, argv, times);

		philo[0].id = 1;
		pthread_create(&(philo[0].thread), NULL, day, philo);
		pthread_join(philo[0].thread, NULL);
		return (0);
	}
}

