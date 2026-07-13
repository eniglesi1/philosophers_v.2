/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 17:36:38 by enmanueligl       #+#    #+#             */
/*   Updated: 2026/07/13 21:06:37 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "limits.h"
#include "string.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	parseo(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc != 5 && argc != 6)
		return (printf("Error: Número de argumentos incorrecto\n"));
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == 0)
			return (printf("Error: Argumento vacío\n"));
		while (argv[i][j])
		{
			if (!(argv[i][j] < 58 && argv[i][j] > 47))
				return (printf("Error: Argumento no númerico o signado\n"));
			j++;
		}
		if (ft_atol(argv[i]) < 1)
			return (printf("Error: Argumento inferior al minimo ( 1 )\n"));
		if (ft_atol(argv[i]) > INT_MAX)
			return (printf("Error: Argumento superior a un entero\n"));
		i++;
	}
	return (1);
}
