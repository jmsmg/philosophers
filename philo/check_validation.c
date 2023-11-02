#include "philo.h"

int	check_range_of_int(int argc, char **argv)
{
	int			i;
	int			j;
	long long	tmp;

	i = 1;
	while (i < argc)
	{
		j = 0;
		tmp = 0;
		while (argv[i][j])
		{
			if (2147483647 < tmp)
			{
				return (FALSE);
			}
			tmp = argv[i][j] * 10 + '0';
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	check_isnumber(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || '9' < argv[i][j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	check_validation(int argc, char argv)
{
	if (!(argc == 5 || argc == 6))
		return (TRUE);
	if (!check_isnumber(argc, argv))
		return (TRUE);
	if (!check_range_of_int(argc, argv))
		return (TRUE);
}
