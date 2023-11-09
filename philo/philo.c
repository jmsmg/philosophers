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
	t_input		input;
	pthread_t		*pthread;
	pthread_mutex_t	*mutex;

	if (!check_validation(argc, argv))
		ft_error(CHECK_VALI);
	init_input(&input);
	// 유효성 재검사?
	make_thread(pthread, mutex);
}
