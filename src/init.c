/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:32:07 by romainthoma       #+#    #+#             */
/*   Updated: 2022/07/24 14:58:49 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_value(t_data *data, char **av)
{
	data->thread = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	data->fork = malloc(sizeof(t_mutex) * ft_atoi(av[1]));
	data->philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	data->is_dead = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	data->last_print = 1;
	data->has_everyone_eaten = 0;
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->number_meal = ft_atoi(av[5]);
	data->stop = 0;
	return (1);
}

void	init_each_thread(t_data *data, int i)
{
	data->philo[i].last_meal = timestamp();
	data->philo[i].meal_took = 0;
	data->philo[i].finish_eating = 0;
	data->philo[i].data = data;
	data->philo[i].philo_number = i + 1;
	data->philo[i].total_number_meal = 0;
	data->philo[i].right_fork = &data->fork[i];
	if (i == data->nb_philo - 1)
		data->philo[i].left_fork = &data->fork[0];
	else
		data->philo[i].left_fork = &data->fork[i + 1];
}
