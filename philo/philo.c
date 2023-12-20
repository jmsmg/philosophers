#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg			arg;
	t_philo			*philo;

	if (!check_validation(argc, argv))
		error_handler();
	init_arg(&arg, argc, argv);
	philo = init_philo(&arg);
	// 유효성 재검사?
	thread_process(&arg, philo);
}
