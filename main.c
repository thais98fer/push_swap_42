#include	"push_swap.h"

int	is_number(char *str)
{
	//Percorre string verificando se cada argumento contém só números.
	if (*str == '+' && *str == '-')
		str++;
	if (*str != '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		*str;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	//atol, verifica se o argumento recebido não ultrapassa o tamanho de int.
	long	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (LONG_MAX);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (LONG_MAX);
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (LONG_MAX);
		str++;
	}
	return (result * sign);
}

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		while (j < i)
		{
			if (argv[j] == argv[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*convert_args(char **argv, int size)
{
	int	*stack_a;
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack_a = (int *)malloc(size * (sizeof(int)));
	if (!stack_a)
		return (NULL);
	while (size != 0)
	{
		stack_a[i] = ft_atoi(argv[j]);
		i++;
		j++;
		size--;
	}
	return (stack_a);
}

#include	<stdio.h>
int	main(int argc, char **argv)
{
	int	*stack_a;
	int	size;
	int	i;

	size = argc - 1;
	i = 0;
	if (argc > 1)
	{
		if (check_args(argv) == 0)
		{
			ft_printf("Error\n");
			return (1);
		}
		stack_a = convert_args(argv, size);
		if (!stack_a)
			return (1);
		while (i < size)
		{
			ft_printf("%d\n", stack_a[i]);
			i++;
		}
	}
	free(stack_a);
	return (0);
}
