#include "push_swap.h"

void	small_sort(t_stack **a, t_stack **b)
{
	int	top;
	int	next;

	if ((*a)->size == 2)
	{
		top = get_index_at(*a, 0);
		next = get_index_at(*a, 1);
		if (top > next)
			sa(a);
	}
	else if ((*a)->size == 3)
		sort_three(a);
	else
	{
		while ((*a)->size > 3)
			push_smallest_to_b(a, b);
		sort_three(a);
		while (!is_empty_stack(*b))
			pa(a, b);
	}
}

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = get_index_at(*a, 0);
	mid = get_index_at(*a, 1);
	bot = get_index_at(*a, 2);
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

int	find_min_pos(t_stack *a)
{
	int		min;
	int		min_pos;
	int		pos;
	t_list	*curr;

	curr = a->head;
	min = ((t_stacknode *)curr->content)->end_index;
	min_pos = 0;
	pos = 0;
	while (curr)
	{
		if (((t_stacknode *)curr->content)->end_index < min)
		{
			min = ((t_stacknode *)curr->content)->end_index;
			min_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}

void	push_smallest_to_b(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = find_min_pos(*a);
	if (min_pos <= (int)(*a)->size / 2)
		while (min_pos-- > 0)
			ra(a);
	else
		while (min_pos++ < (int)(*a)->size)
			rra(a);
	pb(a, b);
}

int	get_index_at(t_stack *stack, int pos)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = stack->head;
	while (curr && i < pos)
	{
		curr = curr->next;
		i++;
	}
	if (!curr)
		return (-1);
	return (((t_stacknode *)curr->content)->end_index);
}
