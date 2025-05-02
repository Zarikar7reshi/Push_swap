#include "push_swap.h"

int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size >> bits) != 0)
		bits++;
	return (bits);
}

int	is_sorted(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(int arr[], int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (arr[i] == arr[i - 1])
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	bubble_sort(int arr[], int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	bind_index_to_value(t_stack **stack, int arr[], int size)
{
	int			i;
	t_list		*curr;
	t_stacknode	*node;

	curr = (*stack)->head;
	while (curr)
	{
		i = 0;
		while (i < size)
		{
			node = curr->content;
			if (node->value == arr[i])
			{
				node->end_index = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}
