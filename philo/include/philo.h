/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:03:58 by seonggoc          #+#    #+#             */
/*   Updated: 2023/12/29 13:02:33 by seonggoc         ###   ########.fr       */
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

enum e_error
{
	CHECK_VALI,
	MUTEX_INIT,
	MUTEX_CREATE,
	INVALID_PHILNUM,
	MALLOCERR
};

typedef struct s_arg
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				option_must_eat;
	long long		start_time;
	int				die;
	int				*fork;
	pthread_mutex_t	*state;
	pthread_mutex_t	*print;
}	t_arg;

typedef struct s_philo
{
	int			id;
	int			left;
	int			right;
	int			last_eat;
	int			eat_cnt;
	int			last_time;
	t_arg		*arg;
}	t_philo;

int			check_validation(int argc, char **argv);

void		init_arg(t_arg *input, int argc, char **argv);

t_philo		*init_philo(t_arg *input);

void		thread_process(t_arg *arg, t_philo *philo);

void		ft_wait_time(t_arg *arg, long long time);
void		philo_printf(t_arg *arg, int id, char *sentence);
long long	ft_get_time(void);

void		ft_bzero(void *s, size_t n);

void		error_handler(int err);
#endif
