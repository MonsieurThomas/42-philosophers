/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:40:22 by romainthoma       #+#    #+#             */
/*   Updated: 2022/07/24 15:14:52 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_all(FORK, philo);
	pthread_mutex_lock(philo->right_fork);
	print_all(FORK, philo);
	print_all(EATING, philo);
	usleep((philo->data->time_to_eat) * 1000);
	if (philo->philo_number == 1297437786)
		philo->philo_number = 1;
	philo->last_meal = timestamp();
	philo->total_number_meal++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_philo *philo)
{
	print_all(SLEEPING, philo);
	usleep ((philo->data->time_to_sleep) * 1000);
	print_all(THINKING, philo);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->philo_number % 2 == 0)
		usleep (777);
	while (42)
	{
		ft_eat(philo);
		philo->meal_took++;
		if (philo->meal_took == philo->data->number_meal)
		{
			print_all(FINISH_EAT, philo);
			philo->data->has_everyone_eaten++;
			break ;
		}
		ft_sleep(philo);
	}
	return (0);
}

int	is_dead_2nd_part(t_philo *philo)
{
	if (philo->data->has_everyone_eaten == philo->data->nb_philo)
	{
		if (philo->data->last_print == 1)
		{
			philo->data->last_print = 0;
			printf("%lld ms Everyone ate their meal\n", timestamp()
				- philo->data->time_start);
		}
		return (1);
	}
	if (diff_time(timestamp(), philo->last_meal)
		>= philo->data->time_to_die)
	{
		if (philo->data->last_print == 1)
		{
			philo->data->last_print = 0;
			print_all(DIED, philo);
		}
		return (1);
	}
	return (0);
}

void	*is_dead(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (42)
	{
		if (is_dead_2nd_part(philo) == 1)
			break ;
		usleep(42);
	}
	pthread_mutex_unlock(&philo->data->mutex_dead);
	return (0);
}
