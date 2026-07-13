/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiglesia <eiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:31:43 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/07/13 21:45:07 by eiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*get_philo(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!philos)
		return (printf("Error: Fallo de malloc\n"), NULL);
	while (i < data->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		i++;
	}
	return (philos);
}

long long	get_time_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((long long)time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_data		data;
	long long	start;
	long long	end;// testing gettimeofday

	if (parseo(argc, argv) == 1)
	{
		start = get_time_ms();
		usleep(250000);
		end = get_time_ms();
		printf("%lld, %lld\n", start, end);
		printf("Han pasado aproximadamente %lld ms\n", end - start);
		data.num_philos = ft_atoi(argv[1]);
		data.time_to_die = ft_atoi(argv[2]);
		data.time_to_eat = ft_atoi(argv[3]);
		data.time_to_sleep = ft_atoi(argv[4]);
		data.num_meals = -1;
		if (argc == 6)
			data.num_meals = ft_atoi(argv[5]);
		philos = get_philo(&data);
		if (!philos)
			return (0);
		pthread_create(&(philos[0].thread), NULL, day, philos);
		pthread_join(philos[0].thread, NULL);
		free(philos);
		return (0);
	}
}

