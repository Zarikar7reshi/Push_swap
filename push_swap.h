#include "stack.h"
#define ATOI_ERRNO 17

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

// stack a
void	sa(t_stack **a);
void	ra(t_stack **a);
void	rra(t_stack **a);
// stack b
void	sb(t_stack **b);
void	rb(t_stack **b);
void	rrb(t_stack **b);
// combined
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// utils
void	parse_args(int ac, char **av, t_stack **a);
// todo: return int if actually performed a move
int		atoi_checked(const char *str, int *errno);
int		is_num(char *str);
void	swap_stack(t_stack **stack);
void	push_stack(t_stack **from, t_stack **to);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);

// sorting utils
int		get_max_bits(int size);
int		has_duplicates(int arr[], int size);
int		is_sorted(int arr[], int size);
int		get_index_at(t_stack *stack, int pos);
void	bubble_sort(int arr[], int size);
void	sort_three(t_stack **a);
void	push_smallest_to_b(t_stack **a, t_stack **b);
void	bind_index_to_value(t_stack **stack, int arr[], int size);

// sorting
int		assign_end_indices(t_stack **stack);
void	push_swap(t_stack **a, t_stack **b);
void	radix_sort_indices(t_stack **a, t_stack **b);
void	small_sort(t_stack **a, t_stack **b);
