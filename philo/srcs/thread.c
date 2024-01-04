/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:16:21 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/04 11:11:15 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_think(t_philo *philo)
{
	if (philo->arg->number_of_philo == 1)
	{
		return ;
	}
	philo_printf(philo->arg, philo->id, "is thinking\n");
}

void	philo_sleep(t_philo *philo)
{
	long long	start;

	if (philo->arg->number_of_philo == 1)
	{
		return ;
	}
	start = get_time();
	philo_printf(philo->arg, philo->id, "is sleeping\n");
	while (get_time() - start <= philo->arg->time_to_sleep)
	{
		usleep(10);
	}
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->arg->pick[philo->left]));
	philo->arg->fork[philo->left] = 1;
	philo_printf(philo->arg, philo->id, "has taken a fork\n");
	if (philo->arg->number_of_philo != 1)
	{
		pthread_mutex_lock(&(philo->arg->pick[philo->right]));
		philo->arg->fork[philo->right] = 1;
		philo_printf(philo->arg, philo->id, "has taken a fork\n");
		philo_printf(philo->arg, philo->id, "is eating\n");
		ft_wait_time(philo, philo->arg->time_to_eat);
		pthread_mutex_lock(philo->arg->eat_cnt);
		philo->eat_cnt++;
		pthread_mutex_unlock(philo->arg->eat_cnt);
		philo->arg->fork[philo->right] = 0;
		pthread_mutex_unlock(&(philo->arg->pick[philo->right]));
		philo->arg->fork[philo->left] = 0;
	}
	pthread_mutex_unlock(&(philo->arg->pick[philo->left]));
}

void	start_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (ft_check_philo_state(philo->arg))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		pthread_mutex_lock(philo->arg->eat_cnt);
		if (philo->eat_cnt == philo->arg->number_of_philo)
		{
			pthread_mutex_unlock(philo->arg->eat_cnt);
			break ;
		}
		pthread_mutex_unlock(philo->arg->eat_cnt);
	}
}

pthread_t	*thread_process(t_arg *arg, t_philo *philo)
{
	int			i;
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t) * arg->number_of_philo);
	if (!thread)
		error_handler(MALLOCERR);
	i = 0;
	while (i < arg->number_of_philo)
	{
		if (pthread_create((&thread[i]), NULL, (void *)start_routine, &philo[i]))
			error_handler(MUTEX_CREATE);
		i++;
	}
	monitor(arg, philo);
	return (thread);
}
