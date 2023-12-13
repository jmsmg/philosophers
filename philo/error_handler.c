/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:03:08 by seonggoc          #+#    #+#             */
/*   Updated: 2023/11/16 16:16:03 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_handler(int	err)
{
	perror("Error");
	if (err == CHECK_VALI)
		printf("Fail check_vaildation");
	else if (err == MUTEX_INIT)
		printf("Fail pthread_mutex_init");
	else if (err == MUTEX_CREATE)
		printf("Fail pthread_mutex_create");

	exit (errno);
}