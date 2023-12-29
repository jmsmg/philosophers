/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:16:21 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/29 19:17:32 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void	philo_think()
// {

// }

void	philo_sleep(t_philo *philo)
{
	if (philo->arg->alive)
	{
		return ;
	}
	philo_printf(philo->arg, philo->id, "is sleeping\n");
	ft_wait_time(philo, philo->arg->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->arg->pick[philo->left]));
	if (philo->arg->fork[philo->left])
	{
		write(1, "left dead lock!!\n", 12);
	}
	philo->arg->fork[philo->left] = 1;
	philo_printf(philo->arg, philo->id, "has taken a left fork\n");
	pthread_mutex_lock(&(philo->arg->pick[philo->right]));
	if (philo->arg->fork[philo->right])
	{
		write(1, "right dead lock!!\n", 12);
	}
	philo->arg->fork[philo->right] = 1;

	philo_printf(philo->arg, philo->id, "has taken a right fork\n");
	philo_printf(philo->arg, philo->id, "is eating\n");
	ft_wait_time(philo, philo->arg->time_to_eat);

	philo->arg->fork[philo->right] = 0;
	pthread_mutex_unlock(&(philo->arg->pick[philo->right]));
	philo->arg->fork[philo->left] = 0;
	pthread_mutex_unlock(&(philo->arg->pick[philo->left]));
	philo->eat_cnt++;
	usleep(100);
}

void	start_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->arg->alive)
	{
		philo_eat(philo);
		philo_sleep(philo);
		// philo_think(philo);
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
	// monitor(arg, philo);
	return (thread);
}
