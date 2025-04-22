#include "push_swap.h"

void ss(t_stack **a, t_stack **b)
{
    swap_stack(a);
    swap_stack(b);
    // ft_printf("ss\n");
    printf("ss\n");
}

void rr(t_stack **a, t_stack **b)
{
    rotate_stack(a);
    rotate_stack(b);
    // ft_printf("rr\n");
    printf("rr\n");
}
void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate_stack(a);
    reverse_rotate_stack(b);
    // ft_printf("rrr\n");
    printf("rrr\n");
}
void pa(t_stack **a, t_stack **b)
{
    push_stack(a, b);
    // ft_printf("pa\n");
    printf("pa\n");
}
void pb(t_stack **a, t_stack **b)
{
    push_stack(b, a);
    // ft_printf("pa\n");
    printf("pb\n");
}
