/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:16:21 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/21 08:15:48 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_make_thread(t_arg *arg)
{
	pthread_mutex_lock(arg->thread_lock);
	arg->thread_num++;
	pthread_mutex_unlock(arg->thread_lock);
	while (arg->thread_num != arg->number_of_philo);
}
void	*start_routine(t_philo *philo)
{
	wait_make_thread(philo->arg);
	// all thread are ready;
}

void	thread_process(t_arg *arg, t_philo *philo)
{
	int	i;
	int	arg;

	i = 0;
	while (i < arg->number_of_philo)
	{
		if (pthread_create(&philo[i], NULL, start_routine, philo) != 0)
			error_handler(MUTEX_CREATE);
		i++;
	}
	i = 0;
}
