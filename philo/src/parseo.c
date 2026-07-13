/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enmanueliglesiasgarciadelcastillo <enma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:36:38 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/07/13 18:12:24 by enmanueligl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*parseo(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc != 5 && argc != 6)
		return (printf("Error: Número de argumentos incorrecto\n"), 0);
	while (argv[i])
	{
		j = 0;
		if (argv[i] == "")
			return (printf("Error: Argumento vacío\n"), 0);
		while (argv[i][j])
		{
			if (!(argv[i][j] < 58 && argv[i][j] > 47))
				return (printf("Error: Argumento no númerico o signado\n"),0);
			j++;
		}
		i++;
	}
	return (1);
}

	// times.num_meals = -1;
	// if (argc == 6)
	// 	times.num_meals = ft_atoi(argv[4]);
