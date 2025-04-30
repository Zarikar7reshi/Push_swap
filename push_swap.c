#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = init_stack('a');
    parse_args(ac, av, &a);
    b = init_stack('b');
    push_swap(&a, &b);

	// t_list *cur = a->head;
	// while (cur)
	// {
	// 	t_stacknode *node = cur->content;
	// 	printf("val: %d, index: %d\n", node->value, node->end_index);
	// 	cur = cur->next;
	// }
	
    free_stack(&a);
    free_stack(&b);
    free(a);
    free(b);
}

// Funzione di push_swap principale
void push_swap(t_stack **a, t_stack **b)
{
	// small sort

	// big sort
	assign_end_indices(a);

	// t_list *cur = (*a)->head;
	// while (cur)
	// {
	// 	t_stacknode *node = cur->content;
	// 	printf("val: %d, index: %d\n", node->value, node->end_index);
	// 	cur = cur->next;
	// }

	radix_sort_indices(a, b);
}
