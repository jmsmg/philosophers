/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:04:55 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/03 09:58:19 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char *argv[])
{
	t_arg		arg;
	t_philo		*philo;
	pthread_t	*thread;

	thread = NULL;
	if (check_validation(argc, argv))
		error_handler(CHECK_VALI);
	init_arg(&arg, argc, argv);
	philo = init_philo(&arg);
	thread = thread_process(&arg, philo);
	free_all(&arg, philo, thread);
}
