/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:16:21 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/27 13:05:11 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(t_philo *philo)
{
	if (philo->id % 2)
		usleep(1000);
	pthread_mutex_lock(&(philo->arg->fork[philo->left])); // 왼쪽포크
	// 
	philo_printf(left);
	monitoring // 사망 체크
	sleep_philo(); // 포크 놓고, 잠
	monitoring() // 사망체크
	

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
