#include "stack.h"
// TODO: atoi errno deve essere 0 (=false) alla fine
#define ATOI_ERRNO 17

void parse_args(int ac, char **av, t_stack **a);

// stack a
void sa(t_stack **a);
void ra(t_stack **a);
void rra(t_stack **a);
// stack b
void sb(t_stack **b);
void rb(t_stack **b);
void rrb(t_stack **b);
// combined
void ss(t_stack **a, t_stack **b);
void rr(t_stack **a, t_stack **b);
void rrr(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);

/*
* functions:
* sa (swap 1st and 2nd of a)
* sb (sa for b)
* ss (sa and sb)
* pa (push first b into a)
* pb (push first a into b)
* ra (rotate a) -> 1st a becomes last
* rb (rotate b)
* rr (ra and rb)
* rra (reverse ra) -> last a becomes 1st
* rrb (reverse rb)
* rrr (rra and rrb)
*/

// utils
void swap_stack(t_stack **stack);
void push_stack(t_stack **to, t_stack **from);
void rotate_stack(t_stack **stack);
void reverse_rotate_stack(t_stack **stack);
int atoi_checked(const char *str, int *errno);

// main sorting
int *median_3(t_stack *stack, int low, int high);
void partition(t_stack **a, t_stack **b, int low, int high);
void quick_sort(t_stack **a, t_stack **b, int low, int high);