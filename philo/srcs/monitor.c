/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:45:41 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/03 19:14:03 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_all(t_arg *arg, t_philo *philo, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philo)
	{
		if (pthread_join(thread[i], NULL))
			error_handler(MUTEX_CREATE);
		i++;
	}
	pthread_mutex_destroy(arg->print);
	i = 0;
	while (i < arg->number_of_philo)
	{
		pthread_mutex_destroy(&arg->pick[i]);
		i++;
	}
	free(arg->print);
	free(arg->pick);
	free(arg->fork);
	free(philo);
}

void	monitor(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	now;

	while (1)
	{
		i = 0;
		while (i < arg->number_of_philo)
		{
			now = get_time();
			pthread_mutex_lock(philo->arg->last_eat);
			if (arg->time_to_alive <= (now - (&philo[i])->last_eat))
			{
				pthread_mutex_lock(philo->arg->alive_mutex);
				arg->alive = 0;
				pthread_mutex_unlock(philo->arg->alive_mutex);
				philo_printf((&philo[i])->arg, (&philo[i])->id, "died\n");
			}
			pthread_mutex_lock(philo->arg->last_eat);
			i++;
		}
	}
}
