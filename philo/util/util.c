/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:31:33 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/04 10:29:08 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_kill_philo(t_arg *arg)
{
	pthread_mutex_lock(arg->alive_mutex);
	arg->alive = 0;
	pthread_mutex_unlock(arg->alive_mutex);
}
int	ft_check_philo_state(t_arg *arg)
{
	pthread_mutex_lock(arg->alive_mutex);
	if (arg->alive)
	{
		pthread_mutex_unlock(arg->alive_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(arg->alive_mutex);
	return (FALSE);
}

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
	if (ft_check_philo_state(arg) == FALSE)
	{
		return ;
	}
	pthread_mutex_lock(arg->print);
	printf("%lld %d %s", get_time() - arg->start_time, id, sentence);
	pthread_mutex_unlock(arg->print);
}
