#include "philo.h"

int	main(int argc, char *argv[])
{
	t_input			input;
	t_philo			*philo;

	if (!check_validation(argc, argv))
		error_handler();
	init_input(&input, argc, argv);
	philo = init_philo(&input);
	// 유효성 재검사?
	make_thread(&input, pthread, mutex);
}
