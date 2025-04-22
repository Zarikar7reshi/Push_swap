#include "push_swap.h"

void sa(t_stack **a)
{
    swap_stack(a);
    // ft_printf("sa\n");
    printf("sa\n");
}

void ra(t_stack **a)
{
    rotate_stack(a);
    // ft_printf("ra\n");
    printf("ra\n");
}

void rra(t_stack **a)
{
    reverse_rotate_stack(a);
    // ft_printf("rra\n");
    printf("rra\n");
}
