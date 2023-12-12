/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:16:21 by seonggoc          #+#    #+#             */
/*   Updated: 2023/11/28 10:18:58 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void)
{
	pthread_mutex_lock(mutex);
	pthread_mutex_unlock(mutex);
}

void	make_thread(t_input *input, pthread_t *pthread, pthread_mutex_t *mutex)
{
	int	arg;

	if (pthread_mutex_init(mutex, NULL) != 0)
		error_handler(MUTEX_INIT);
	if (pthread_create(pthread, NULL, start_routine, (void *)&arg) != 0)
		error_handler(MUTEX_CREATE);
	pthread_join(pthread, NULL);
	pthread_mutex_destroy(mutex);
}
