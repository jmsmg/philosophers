/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:31:33 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/29 19:17:32 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_wait_time(t_philo *philo, long long time)
{
	long long	start;

	start = get_time();
	while (philo->arg->alive && get_time() - start <= time)
	{
		usleep(10);
	}
}

long long	get_time()
{
	struct timeval	tp;
	long long	time;

	gettimeofday(&tp, NULL);
	time = tp.tv_usec;
	time /= 1000;
	return (time);
}

void	philo_printf(t_arg *arg, int id, char *sentence)
{
	pthread_mutex_lock(arg->print);
	printf("%lld %d %s", get_time() - arg->start_time, id, sentence);
	pthread_mutex_unlock(arg->print);
}
