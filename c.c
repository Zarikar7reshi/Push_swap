#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
}

void	pa(t_stack **a, t_stack **b)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}
