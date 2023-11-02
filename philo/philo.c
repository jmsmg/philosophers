#include "philo.h"

void	ft_error(int err)
{
	if (err == CHECK_VALI)
	{
		printf("validation failed");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	int			a;
	t_input		input;
	pthread_t		*pthread;
	pthread_mutex_t	*mutex;

	if (!check_validation(argc, argv))
		ft_error(CHECK_VALI);
	init_input(&input);
	pthread_mutex_init(mutex, NULL);
	pthread_create(pthread, NULL, start_routine, (void *)a);
}
