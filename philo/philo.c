/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:04:55 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/28 11:13:11 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char *argv[])
{
	t_arg			arg;
	t_philo			*philo;

	if (check_validation(argc, argv))
		error_handler(CHECK_VALI);
	init_arg(&arg, argc, argv);
	philo = init_philo(&arg);
	// 유효성 재검사?
	thread_process(&arg, philo);
}
