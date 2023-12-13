/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:54:06 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/13 16:10:16 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_input *input)
{
	int		i;
	t_philo	*philo;

	philo = malloc((sizeof(t_philo) * input->number_of_philo));
	i = 0;
	while (i < input->number_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].left = i;
		philo[i].right = i + 1 % input->number_of_philo;
		philo[i].last_eat = 0;
		philo[i].last_time = 0;
		i++;
	}
	return (philo);
}
