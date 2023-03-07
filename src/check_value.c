/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:40:51 by romainthoma       #+#    #+#             */
/*   Updated: 2022/07/24 14:54:57 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_value_2nd(char **av)
{
	int	max;

	max = 2147483647;
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[1]) > 200)
	{
		printf("The number of philosophers must be between 0 and 200\n");
		return (0);
	}
	if (ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0 || ft_atoi(av[4])
		< 0 || ft_atoi(av[2]) > max || ft_atoi(av[3]) > max
		|| ft_atoi(av[4]) > max)
	{
		printf("Your args must be between 0 and max int\n");
		return (0);
	}
	if (av[5])
	{
		if (ft_atoi(av[5]) < 0 || ft_atoi(av[1]) >= max)
		{
			printf("The number of meal must be between 0 and max int\n");
			return (0);
		}
	}
	return (1);
}

int	check_value(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 5 || ac > 6)
	{
		printf("You must give 4 ou 5 arguments\n");
		return (0);
	}
	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-')
			{
				printf("The arguments must be numbers only\n");
				return (0);
			}
		}
	}
	if (!check_value_2nd(av))
		return (0);
	return (1);
}
