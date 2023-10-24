#include "philosopher.h"

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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_validation(int argc, char argv)
{
	if (!(argc == 5 || argc == 6))
		return (1);
	if (!check_isnumber(argc, argv))
		return (1);
}
