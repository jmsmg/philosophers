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
	t_philo philo;

	if (!check_validation(argc, argv))
		ft_error(CHECK_VALI);
	init_philo(&philo);
	init_thread();
}
