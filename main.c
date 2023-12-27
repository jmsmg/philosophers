#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

int	get_time()
{
	int		time;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1000000 + tp.tv_usec;
	return (time);
}

void	*start_routine(void *data)
{
	int	now;
	int	curr;

	pthread_mutex_lock(&mutex);
	now = get_time();
	(*(int *)data)++;
	pthread_mutex_unlock(&mutex);
	curr = get_time();
	while (curr < now)
	{
		usleep(100);
	}
	printf("data : %d\n", *((int *)data));
	return (NULL);
}

int	main()
{
	int			i;
	int			j;
	int			status;
	pthread_t	pthread[100];

	i = 0;
	j = 0;
	while (i < 100)
	{
		if (pthread_create(&pthread[i], NULL, &start_routine, (void *)&j) < 0)
		{
			return 1;
		}
		i++;
	}

	while (i < 100)
	{
		pthread_join(pthread[i], (void **)&status);
		i++;
	}
}
