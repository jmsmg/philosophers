/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:08:12 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/20 11:21:03 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*init_philo(t_arg *arg)
{
	int		i;
	t_philo	*philo;

	philo = malloc((sizeof(t_philo) * arg->number_of_philo));
	i = 0;
	while (i < arg->number_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].left = i;
		philo[i].right = (i + 1) % arg->number_of_philo;
		philo[i].last_eat = ft_get_time();
		philo[i].last_time = 0;
		i++;
	}
	return (philo);
}

void	make_fork(t_arg *arg)
{
	arg->fork = malloc(sizeof(int) * arg->number_of_philo);
	if (!(arg->fork))
		error_handler(MALLOCERR);
	ft_bzero(arg->fork, sizeof(int) * arg->number_of_philo);
	arg->state = malloc(sizeof(pthread_mutex_t) * arg->number_of_philo);
	if (!(arg->state))
		error_handler(MALLOCERR);
	if (pthread_mutex_init(arg->state, NULL))
		error_handler(MUTEX_INIT);
}

long long	philo_atoi(char	*str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void	init_arg(t_arg *arg, int argc, char **argv)
{
	arg->number_of_philo = philo_atoi(argv[1]);
	if (arg->number_of_philo < 2)
		error_handler(INVALID_PHILNUM);
	arg->time_to_die = philo_atoi(argv[2]);
	arg->time_to_eat = philo_atoi(argv[3]);
	arg->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		arg->option_must_eat = philo_atoi(argv[5]);
	else
		arg->option_must_eat = -1;
	arg->die = 1;
	make_fork(arg);
	if (pthread_mutex_init(arg->print, NULL))
		error_handler(MUTEX_INIT);
}
