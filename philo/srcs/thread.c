/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:16:21 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/28 12:15:27 by seonggoc         ###   ########.fr       */
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

	i = 0;
	pthread_mutex_lock(&(philo->arg->state[i]));
	if (philo->left == 0)
		philo->left = 1;
	if (philo->right == 0)
		philo->right = 1;
	pthread_mutex_unlock(&(philo->arg->state[i]));
	usleep(200);
}

void	start_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while ()
	{
		philo_eat(philo);
		// philo_sleep(philo);
		// philo_think(philo);
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
