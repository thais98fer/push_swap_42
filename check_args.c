#include	"push_swap.h"

int	is_number(char *str)
{
	while (*str == '+' || *str == '-' || *str == ' ' || *str == '\t')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if(!is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
