#include "push_swap.h"

int get_max_bits(int size)
{
    int bits = 0;
    while ((size >> bits) != 0)
        bits++;
    return bits;
}

void radix_sort_indices(t_stack **a, t_stack **b)
{
    int size = (*a)->size;
    int max_bits = get_max_bits(size - 1);

    for (int i = 0; i < max_bits; i++)
    {
        int j = 0;
        int count = (*a)->size;

        while (j < count)
        {
            t_stacknode *node = (t_stacknode *)(*a)->head->content;
            if ((node->end_index >> i) & 1)
                ra(a);  // bit = 1 → ruota in fondo
            else
                pb(a, b); // bit = 0 → push in b
            j++;
        }

        while (!is_empty_stack(*b))
            pa(a, b);
    }
}
