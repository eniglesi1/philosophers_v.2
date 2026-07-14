/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enmanueliglesiasgarciadelcastillo <enma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:31:43 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/07/14 13:41:57 by enmanueligl      ###   ########.fr       */
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
		philos[i].last_meal = data->born_time;
		philos[i].hungry = philos[i].id % 2;
		philos[i].meals = 0;
		philos[i].last_turn = 0;
		if (pthread_mutex_init(&philos[i].r_fork, NULL) != 0)
			return (free(philos), NULL);
		if (i == 0)
			philos[i].l_fork = &philos[data->num_philos - 1].r_fork;
		else
			philos[i].l_fork = &philos[i - 1].r_fork;
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

static int	run_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, day, &philos[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->num_philos)
		pthread_join(philos[i++].thread, NULL);
	i = 0;
	while (i < data->num_philos)
		pthread_mutex_destroy(&philos[i++].r_fork);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_data		data;

	if (parseo(argc, argv) != 1)
		return (1);
	data.num_philos = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	data.num_meals = -1;
	if (argc == 6)
		data.num_meals = ft_atoi(argv[5]);
	data.greaper = 0;
	data.born_time = get_time_ms();
	pthread_mutex_init(&data.dead, NULL);
	pthread_mutex_init(&data.print, NULL);
	philos = get_philo(&data);
	if (!philos)
		return (0);
	if (run_threads(philos, &data) != 0)
		return (free(philos), 1);
	pthread_mutex_destroy(&data.dead);
	pthread_mutex_destroy(&data.print);
	free(philos);
	return (0);
}
