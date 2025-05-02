#include "push_swap.h"

// bit = 1 -> ruota in fondo
// bit = 0 -> push in b
void	radix_sort_indices(t_stack **a, t_stack **b)
{
	int	count;
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	max_bits = get_max_bits((*a)->size - 1);
	while (i < max_bits)
	{
		j = 0;
		count = (*a)->size;
		while (j < count)
		{
			if ((((t_stacknode *)(*a)->head->content)->end_index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (!is_empty_stack(*b))
			pa(a, b);
		i++;
	}
}

int	assign_end_indices(t_stack **stack)
{
	int		i;
	int		size;
	int		*arr;
	t_list	*curr;

	i = 0;
	size = (*stack)->size;
	arr = malloc(sizeof(int) * size);
	curr = (*stack)->head;
	while (i < size && curr != NULL)
	{
		arr[i] = ((t_stacknode *)curr->content)->value;
		curr = curr->next;
		i++;
	}
	if (is_sorted(arr, size))
		return (free_stack(stack), free(arr), 0);
	bubble_sort(arr, size);
	if (has_duplicates(arr, size))
		return (free_stack(stack), free(arr), 0);
	bind_index_to_value(stack, arr, size);
	return (free(arr), 1);
}
