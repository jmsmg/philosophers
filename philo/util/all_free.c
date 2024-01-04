/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:16:39 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/04 12:17:02 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	all_destroy(t_arg *arg)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(arg->alive_mutex);
	pthread_mutex_destroy(arg->last_eat);
	pthread_mutex_destroy(arg->eat_cnt);
	pthread_mutex_destroy(arg->print);
	i = 0;
	while (i < arg->number_of_philo)
	{
		pthread_mutex_destroy(&arg->pick[i]);
		i++;
	}
}

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
	all_destroy(arg);
	free(arg->fork);
	free(arg->pick);
	free(arg->alive_mutex);
	free(arg->eat_cnt);
	free(arg->last_eat);
	free(arg->print);
	free(philo);
}
