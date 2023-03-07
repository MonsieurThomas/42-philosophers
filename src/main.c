/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:18:24 by romainthoma       #+#    #+#             */
/*   Updated: 2022/07/23 20:17:11 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philo_main(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->writing, NULL);
	data->time_start = timestamp();
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		init_each_thread(data, i);
		if (pthread_create(&data->thread[i], NULL, &routine, &data->philo[i]))
			return ;
		pthread_detach(data->thread[i]);
		if (pthread_create(&data->is_dead[i], NULL, &is_dead, &data->philo[i]))
			return ;
		pthread_detach(data->is_dead[i]);
		i++;
	}
}

void	aiguillage_mutex(t_data *data)
{
	pthread_mutex_init(&data->mutex_dead, NULL);
	pthread_mutex_lock(&data->mutex_dead);
	philo_main(data);
	pthread_mutex_lock(&data->mutex_dead);
	pthread_mutex_unlock(&data->mutex_dead);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	if (!check_value(ac, av))
		return (0);
	if (!init_value(&data, av))
		return (0);
	aiguillage_mutex(&data);
	return (0);
}
