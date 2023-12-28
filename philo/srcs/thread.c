/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:16:21 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/28 21:21:37 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void	philo_think()
// {

// }

// void	philo_sleep()
// {

// }

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->arg->state[philo->left]));
	philo->arg->fork[philo->left] = 1;
	philo_printf(philo->arg, philo->id, "pick up left fork\n");


	pthread_mutex_lock(&(philo->arg->state[philo->right]));
	philo->arg->fork[philo->right] = 1;
	philo_printf(philo->arg, philo->id, "pick up right fork\n");
	philo_printf(philo->arg, philo->id, "eat\n");
	// 시간 측정

	philo->arg->fork[philo->right] = 0;
	pthread_mutex_unlock(&(philo->arg->state[philo->right]));
	philo->arg->fork[philo->left] = 0;
	pthread_mutex_unlock(&(philo->arg->state[philo->left]));
	usleep(200);
}

void	start_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->arg->die)
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
		if (pthread_create(&(thread[i]), NULL, (void *)start_routine, &philo[i]))
			error_handler(MUTEX_CREATE);
		i++;
	}
	i = 0;
	while (i < arg->number_of_philo)
	{
		if (pthread_join(thread[i], NULL))
			error_handler(MUTEX_CREATE);
		i++;
	}
	// all_free_destroy();
	pthread_mutex_destroy(arg->print);
	free(arg->print);
	int	j;

	j = 0;
	while (i < arg->number_of_philo)
	{
		pthread_mutex_destroy(&arg->state[i]);
		j++;
	}
	free(arg->state);
	exit(1);
}
