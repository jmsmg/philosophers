/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:31:33 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/03 09:32:31 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_wait_time(t_philo *philo, long long time)
{
	long long	start;

	start = get_time();
	pthread_mutex_lock(philo->arg->time);
	philo->last_eat = start;
	while (philo->arg->alive && get_time() - start <= time)
	{
		usleep(10);
	}
	pthread_mutex_unlock(philo->arg->time);
}

long long	get_time()
{
	struct timeval	tp;
	long long	time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000000) + tp.tv_usec;
	time /= 1000;
	return (time);
}

void	philo_printf(t_arg *arg, int id, char *sentence)
{
	pthread_mutex_lock(arg->print);
	printf("%lld %d %s", get_time() - arg->start_time, id, sentence);
	pthread_mutex_unlock(arg->print);
}
