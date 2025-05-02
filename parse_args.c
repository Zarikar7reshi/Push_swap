#include "push_swap.h"

static void	error(t_stack **a);

void	parse_args(int ac, char **av, t_stack **a)
{
	int			i;
	t_stacknode	*num;

	i = ac - 1;
	while (i >= 1)
	{
		if (is_num(av[i]) && ac >= 2)
		{
			num = (t_stacknode *)malloc(sizeof(t_stacknode));
			if (!num)
				error(a);
			num->value = ft_atoi(av[i]);
			push(a, num);
			i--;
		}
		else
			error(a);
	}
}

static void	error(t_stack **a)
{
	ft_printf("Error\n");
	free_stack(a);
	exit(EXIT_FAILURE);
}
