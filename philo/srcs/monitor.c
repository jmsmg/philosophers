/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:45:41 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/04 12:20:06 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_check_eat_cnt(t_philo *philo)
{
	pthread_mutex_lock(philo->arg->eat_cnt);
	if (philo->eat_cnt == philo->arg->option_must_eat)
	{
		pthread_mutex_unlock(philo->arg->eat_cnt);
		return (FALSE);
	}
	pthread_mutex_unlock(philo->arg->eat_cnt);
	return (TRUE);
}

void	monitor(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	eat;
	long long	now;

	i = 0;
	while (ft_check_philo_state(arg) && ft_check_eat_cnt(philo))
	{
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
