/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:45:41 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/04 11:12:40 by seonggoc         ###   ########.fr       */
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
	while (ft_check_philo_state(arg))
	{
		pthread_mutex_lock(philo->arg->eat_cnt);
		if (philo->eat_cnt == philo->arg->option_must_eat)
		{
			pthread_mutex_unlock(philo->arg->eat_cnt);
			break ;
		}
		pthread_mutex_unlock(philo->arg->eat_cnt);
		i = 0;
		while (i < arg->number_of_philo)
		{
			now = get_time();
			pthread_mutex_lock(philo->arg->last_eat);
			eat = philo[i].last_eat;
			pthread_mutex_unlock(philo->arg->last_eat);
			if (arg->time_to_alive <= (now - eat))
			{
				philo_printf((&philo[i])->arg, (&philo[i])->id, "died\n");
				ft_kill_philo(arg);
			}
			i++;
		}
	}
}
