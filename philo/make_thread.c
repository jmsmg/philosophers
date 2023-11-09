#include "philo.h"

void	*start_routine(void)
{
	pthread_mutex_lock(mutex);
	pthread_mutex_unlock(mutex);
}

void	make_thread(pthread_t *pthread, pthread_mutex_t *mutex)
{
	int	a;


	pthread_mutex_init(mutex, NULL);
	if (pthread_create(pthread, NULL, start_routine, (void *)&a) < 0)
	{
		perror("thread create error");
	}
	pthread_join(pthread, NULL);
	pthread_mutex_destroy(mutex);
}
