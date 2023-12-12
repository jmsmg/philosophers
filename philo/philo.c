#include "philo.h"

int	main(int argc, char *argv[])
{
	t_input			input;
	t_philo			philo;
	pthread_t		*pthread;
	pthread_mutex_t	*mutex;

	if (!check_validation(argc, argv))
		error_handler();
	init_input(&input, argc, argv);
	// 유효성 재검사?
	make_thread(&input, pthread, mutex);
}
