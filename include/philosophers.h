/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:44:12 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/24 14:58:33 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define FINISH_EAT 6
# define FINISH_EAT_ALL 7

typedef struct s_data	t_data;

typedef struct s_mutex
{
	pthread_mutex_t		fork;

}	t_mutex;

typedef struct s_philo
{
	int					philo_number;

	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
	int					meal_took;
	int					finish_eating;
	int					total_number_meal;

	long long			last_meal;

}	t_philo;

typedef struct s_data
{	
	int					nb_philo;

	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					number_meal;

	int					stop;
	int					last_print;
	long long			time_start;
	int					has_everyone_eaten;

	pthread_mutex_t		*fork;
	pthread_mutex_t		writing;
	pthread_mutex_t		mutex_dead;
	t_philo				*philo;
	pthread_t			*thread;
	pthread_t			*is_dead;

}	t_data;

void			ft_putnbr(int nb);
void			ft_putstr(char *s);
long long		timestamp(void);
long long		diff_time(long long a, long long b);
long long		timestamp(void);
int				ft_atoi(const char *str);
void			init_each_thread(t_data *data, int i);
int				init_value(t_data *data, char **av);
void			print_all(int action, t_philo *philo);
int				check_value(int ac, char **av);
void			*routine(void *ptr);
void			*is_dead(void *ptr);

#endif
