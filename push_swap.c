#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack('a');
	parse_args(ac, av, &a);
	b = init_stack('b');
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
}

// t_list *cur = a->head;
// while (cur)
// {
// 	t_stacknode *node = cur->content;
// 	printf("val: %d, index: %d\n", node->value, node->end_index);
// 	cur = cur->next;
// }

// Funzione di push_swap principale
void	push_swap(t_stack **a, t_stack **b)
{
	if (assign_end_indices(a))
	{
		if ((*a)->size > 5)
			radix_sort_indices(a, b);
		else
			small_sort(a, b);
	}
	else
	{
		free_stack(b);
		exit(EXIT_FAILURE);
	}
}
