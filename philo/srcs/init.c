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
		philo[i].last_eat = get_time();
		philo[i].eat_cnt = 0;
		philo[i].arg = arg;
		i++;
	}
	return (philo);
}

void	make_mutex(t_arg *arg)
{
	pthread_mutex_t	*last_eat;
	pthread_mutex_t	*eat_cnt;
	pthread_mutex_t	*print;

	last_eat = malloc(sizeof(pthread_mutex_t));
	if (!last_eat)
		error_handler(MALLOCERR);
	eat_cnt = malloc(sizeof(pthread_mutex_t));
	if (!eat_cnt)
		error_handler(MALLOCERR);
	print = malloc(sizeof(pthread_mutex_t));
	if (!print)
		error_handler(MALLOCERR);
	if (pthread_mutex_init(eat_cnt, NULL))
		error_handler(MUTEX_INIT);
	if (pthread_mutex_init(last_eat, NULL))
		error_handler(MUTEX_INIT);
	if (pthread_mutex_init(print, NULL))
		error_handler(MUTEX_INIT);
	arg->last_eat = last_eat;
	arg->eat_cnt = eat_cnt;
	arg->print = print;
}

void	make_fork(t_arg *arg)
{
	int	i;

	i = 0;
	arg->fork = malloc(sizeof(int) * arg->number_of_philo);
	if (!(arg->fork))
		error_handler(MALLOCERR);
	ft_bzero(arg->fork, sizeof(int) * arg->number_of_philo);
	arg->pick = malloc(sizeof(pthread_mutex_t) * arg->number_of_philo);
	if (!(arg->pick))
		error_handler(MALLOCERR);
	while (i < arg->number_of_philo)
	{
		if (pthread_mutex_init(&(arg->pick[i]), NULL))
			error_handler(MUTEX_INIT);
		i++;
	}
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
	pthread_mutex_t	*alive_mutex;

	arg->number_of_philo = philo_atoi(argv[1]);
	arg->time_to_alive = philo_atoi(argv[2]);
	arg->time_to_eat = philo_atoi(argv[3]);
	arg->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		arg->option_must_eat = philo_atoi(argv[5]);
	else
		arg->option_must_eat = -1;
	arg->start_time = get_time();
	arg->alive = 1;
	make_fork(arg);
	make_mutex(arg);
	alive_mutex = malloc(sizeof(pthread_mutex_t));
	if (!alive_mutex)
		error_handler(MUTEX_INIT);
	arg->alive_mutex = alive_mutex;
}
