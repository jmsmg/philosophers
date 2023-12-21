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
	time = 0;
	printf("gettime : %ld\n", tp.tv_sec);
	return (time);
}

void	*start_routine(void *data)
{
	int	time;

	while (*((int *)data) == 99);
	pthread_mutex_lock(&mutex);
	time = get_time();
	printf("data : %d, time: %d\n", *((int *)data), time);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main()
{
	int			i;
	int			status;
	pthread_t	pthread[100];

	i = 0;
	while (i < 100)
	{
		if (pthread_create(&pthread[i], NULL, &start_routine, (void *)&i) < 0)
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
