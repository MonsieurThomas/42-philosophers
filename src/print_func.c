/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:31:47 by romainthoma       #+#    #+#             */
/*   Updated: 2022/07/24 15:14:43 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_all(int action, t_philo *philo)
{
	long long	lld;
	int			d;

	lld = timestamp() - philo->data->time_start;
	d = philo->philo_number;
	if (philo->data->stop != 0)
		return ;
	pthread_mutex_lock(&philo->data->writing);
	if (action == FORK)
		printf("%lld ms %d has taken a fork\n", lld, d);
	if (action == EATING)
		printf("%lld ms %d is eating\n", lld, d);
	if (action == THINKING)
		printf("%lld ms %d is thinking\n", lld, d);
	if (action == SLEEPING)
		printf("%lld ms %d is sleeping\n", lld, d);
	if (action == DIED)
	{
		philo->data->stop++;
		printf("%lld ms %d has died\n", lld, d);
	}
	pthread_mutex_unlock(&philo->data->writing);
}
