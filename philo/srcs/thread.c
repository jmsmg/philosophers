/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:16:21 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/27 17:08:39 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_think()
{

}

void	philo_sleep()
{

}

void	philo_eat(t_philo *philo)
{
	int	i;

	if (philo->id % 2)
		usleep(1000);
	i = 0;
	while (i < )
	pthread_mutex_lock(philo->arg->state);
	philo->id
	pthread_mutex_unlock(philo->arg->state);
}

void	*start_routine(t_philo *philo)
{
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	thread_process(t_arg *arg, t_philo *philo)
{
	int			i;
	pthread_t	thread[arg->number_of_philo];

	i = 0;
	while (i < arg->number_of_philo)
	{
		if (pthread_create(&(thread[i]) , NULL, (void *)start_routine, philo) != 0)
			error_handler(MUTEX_CREATE);
		i++;
	}
	i = 0;
}
