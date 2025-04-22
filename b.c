#include "push_swap.h"

void sb(t_stack **b)
{
    swap_stack(b);
    // ft_printf("sb\n");
    printf("sb\n");
}

void rb(t_stack **b)
{
    rotate_stack(b);
    // ft_printf("rb\n");
    printf("rb\n");
}

void rrb(t_stack **b)
{
    reverse_rotate_stack(b);
    // ft_printf("rrb\n");
    printf("rrb\n");
}