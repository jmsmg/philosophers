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

void	init_input(t_input *input, int argc, char **argv)
{
	input->number_of_philo = philo_atoi(argv[1]);
	input->time_to_die = philo_atoi(argv[2]);
	input->time_to_eat = philo_atoi(argv[3]);
	input->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		input->option_must_eat = philo_atoi(argv[5]);
	else
		input->option_must_eat = 0;
}
