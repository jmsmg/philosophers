/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:03:58 by seonggoc          #+#    #+#             */
/*   Updated: 2023/11/16 18:55:37 by seonggoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define TRUE 1
# define FALSE 0

enum s_error
{
	CHECK_VALI,
	MUTEX_INIT,
	MUTEX_CREATE
};

typedef struct s_input
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int option_must_eat;
} t_input;

typedef struct s_philo
{
	int	philo;
	int	count;
	int	left;
	int	right;
	int	last_eat;
	int	last_time;
	int	arg;
}	t_philo;

int		check_validation(int argc, char **argv);

void	init_input(t_input *input, int argc, char **argv);

void	make_thread(t_input *input, pthread_t *pthread, pthread_mutex_t *mutex);


#endif
