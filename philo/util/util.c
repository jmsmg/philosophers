/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:31:33 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/03 19:53:48 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_wait_time(t_philo *philo, long long time)
{
	long long	start;

	start = get_time();
	pthread_mutex_lock(philo->arg->last_eat);
	philo->last_eat = start;
	pthread_mutex_unlock(philo->arg->last_eat);
	while (get_time() - start <= time)
	{
		usleep(10);
	}
}

long long	get_time(void)
{
	long long		time;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000000) + tp.tv_usec;
	time /= 1000;
	return (time);
}

void	philo_printf(t_arg *arg, int id, char *sentence)
{
	int	flag;

	pthread_mutex_lock(arg->alive_mutex);
	flag = arg->alive;
	pthread_mutex_unlock(arg->alive_mutex);
	if (flag == 0)
	{
		return ;
	}
	pthread_mutex_lock(arg->print);
	printf("%lld %d %s", get_time() - arg->start_time, id, sentence);
	pthread_mutex_unlock(arg->print);
}
