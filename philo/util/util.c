/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:31:33 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/22 16:13:48 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_get_time()
{
	int				time;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1000000 + tp.tv_usec;
	time /= 1000;
	return (time);
}

void	philo_printf(int time, int id, char *sentence)
{
	pthread_mutex_t	mutex;

	pthread_mutex_lock(&mutex);
	printf("%d %d %s", time, id, sentence);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex); // arg에 넣고 추후에 삭제 고려
}
