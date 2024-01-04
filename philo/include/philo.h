/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggoc <seonggoc@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:03:58 by seonggoc          #+#    #+#             */
/*   Updated: 2024/01/04 10:24:37 by seonggoc         ###   ########.fr       */
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
	long long		time_to_alive;
	int				time_to_eat;
	int				time_to_sleep;
	int				option_must_eat;
	long long		start_time;
	int				alive;
	int				*fork;
	pthread_mutex_t	*alive_mutex;
	pthread_mutex_t	*pick;
	pthread_mutex_t	*last_eat;
	pthread_mutex_t	*eat_cnt;
	pthread_mutex_t	*print;
}	t_arg;

typedef struct s_philo
{
	int			id;
	int			left;
	int			right;
	int			eat_cnt;
	long long	last_eat;
	t_arg		*arg;
}	t_philo;

int			check_validation(int argc, char **argv);

void		init_arg(t_arg *input, int argc, char **argv);

t_philo		*init_philo(t_arg *input);

pthread_t	*thread_process(t_arg *arg, t_philo *philo);

int			ft_check_philo_state(t_arg *arg);
void		ft_kill_philo(t_arg *arg);
void		ft_wait_time(t_philo *philo, long long time);
void		philo_printf(t_arg *arg, int id, char *sentence);
long long	get_time(void);

void		ft_bzero(void *s, size_t n);

void		error_handler(int err);

void		monitor(t_arg *arg, t_philo *philo);
void		free_all(t_arg *arg, t_philo *philo, pthread_t *thread);
#endif
