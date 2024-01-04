/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:45:41 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/04 09:40:10 by seonggoc         ###   ########.fr       */
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
	free(arg->alive_mutex);
	free(arg->last_eat);
	free(arg->pick);
	free(arg->fork);
	free(philo);
}

void	monitor(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	eat;
	long long	now;

	i = 0;
	while (philo->arg->alive)
	{
		i = 0;
		while (i < arg->number_of_philo)
		{
			now = get_time();
			pthread_mutex_lock(philo->arg->eat_cnt);
			if (philo->eat_cnt == philo->arg->option_must_eat)
			{
				pthread_mutex_lock(philo->arg->alive_mutex);
				arg->alive = 0;
				pthread_mutex_unlock(philo->arg->alive_mutex);
				philo_printf((&philo[i])->arg, (&philo[i])->id, "died\n");
				printf("died\n");
			}
			pthread_mutex_unlock(philo->arg->eat_cnt);
			pthread_mutex_lock(philo->arg->last_eat);
			eat = philo[i].last_eat;
			pthread_mutex_unlock(philo->arg->last_eat);
			if (arg->time_to_alive <= (now - eat))
			{
				pthread_mutex_lock(philo->arg->alive_mutex);
				arg->alive = 0;
				pthread_mutex_unlock(philo->arg->alive_mutex);
				philo_printf((&philo[i])->arg, (&philo[i])->id, "died\n");
				printf("died\n");
			}
			i++;
		}
	}
}
