/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:45:41 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/29 19:17:32 by seonggoc         ###   ########.fr       */
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

	while (arg->alive)
	{
		if (philo[i].eat_cnt == arg->option_must_eat)
		{
			arg->alive = 0;
			break ;
		}
		i = 0;
		while (i < arg->number_of_philo)
		{
			now = get_time();
			if (arg->time_to_alive <= (now - (&philo[i])->last_eat))
			{
				arg->alive = 0;
				philo_printf((&philo[i])->arg, (&philo[i])->id, "alived\n");
				break ;
			}
			i++;
		}
	}
}
