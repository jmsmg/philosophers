#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		a = 0;
pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
void	*start_routine(void *data)
{
	int	i;
	while (*((int *)data) == 99);
	printf("%d\n", *((int *)data));
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
	write(1, (char *)data, 9);
	i = 0;
	while (i < 50000)
	{
		a++;
		i++;
	}
	printf("data : %s, a: %d\n", (char *)data, a);
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
