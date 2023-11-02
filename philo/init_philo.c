#include "philo.h"

long long	philo_atoi(char	*str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = str[i] * 10 + '0';
		i++;
	}
	return (result);
}

void	init_philo(t_philo *philo, int argc, char **argv)
{
	philo->number_of_philo = philo_atoi(argv[1]);
	philo->time_to_die = philo_atoi(argv[2]);
	philo->time_to_eat = philo_atoi(argv[3]);
	philo->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		philo->option_must_eat = philo_atoi(argv[5]);
}
