#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = (t_stack *)malloc(sizeof(t_stack));
    b = (t_stack *)malloc(sizeof(t_stack));
    init_stack(&a, 'a');
    init_stack(&b, 'b');
    parse_args(ac, av, &a);
    quick_sort(&a, &b, 0, a->size - 1);

    printf("[");
    while (!is_empty_stack(a)) {
        int* value = (int*)pop(&a);
        printf("%d, ", *value);
        free(value);
    }
    printf("]");
    
    free_stack(&a);
    free_stack(&b);
    free(a);
    free(b);
}

#include <stdio.h>
#include <stdlib.h>

// Definizioni delle strutture e delle funzioni necessarie
typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

// Funzioni per le mosse
void push_stack(t_stack **src, t_stack **dst);
void rotate_stack(t_stack **stack);
void reverse_rotate_stack(t_stack **stack);
void swap_stack(t_stack **stack);

// Funzioni di ordinamento
void radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
void insertion_sort(t_stack **stack_a, t_stack **stack_b, int size);

// Funzione di utilità
int get_max_bits(int size);
void push_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_size);
int stack_size(t_stack *stack);
void divide_into_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size);
void sort_remaining(t_stack **stack_a, t_stack **stack_b);

void assign_end_indices(t_stack *stack)
{
    int size = stack_size(stack);
    int *arr = malloc(sizeof(int) * size);
    t_stack *tmp = stack;

    // Copia dei valori
    for (int i = 0; i < size; i++, tmp = tmp->next)
        arr[i] = tmp->value;

    // Ordina l'array (bubble sort per semplicità, usa qsort per efficienza)
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    // Assegna gli end_index ai nodi
    tmp = stack;
    while (tmp)
    {
        for (int i = 0; i < size; i++)
        {
            if (tmp->value == arr[i])
            {
                tmp->end_index = i;
                break;
            }
        }
        tmp = tmp->next;
    }

    free(arr);
}

// Funzione di push_swap principale
void push_swap(t_stack **stack_a, t_stack **stack_b)
{
    int size = stack_size(*stack_a);
    int chunk_size = 10; // Dimensione dei chunk, puoi modificarla

    // Passo 1: Ordina i chunk
    divide_into_chunks(stack_a, stack_b, chunk_size);

    // Passo 2: Ordina i rimanenti usando insertion sort
    sort_remaining(stack_a, stack_b);
}

// Funzione per ordinare i chunk con radix sort
void divide_into_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
    int size = stack_size(*stack_a);
    int max_bits = get_max_bits(size);

    // Radix Sort su ciascun chunk
    for (int bit = 0; bit < max_bits; bit++)
    {
        push_to_b(stack_a, stack_b, chunk_size);
        // Ora ordina gli elementi da b a a con push e rotate
        // Devono tornare in a ordinati
        while (*stack_b)
        {
            push_stack(stack_b, stack_a);
        }
    }
}

// Funzione per pushare gli elementi da stack_a a stack_b per ogni chunk
void push_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
    for (int i = 0; i < chunk_size && *stack_a; i++)
    {
        // Aggiungi l'elemento allo stack_b
        push_stack(stack_a, stack_b);
        // Fai delle rotazioni per distribuire gli elementi correttamente in b
        rotate_stack(stack_b);
    }
}
int get_max_bits(int max_index)
{
    int bits = 0;
    while ((max_index >> bits) != 0)
        bits++;
    return bits;
}
void radix_sort_indices(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int max_bits = get_max_bits(size - 1);

    for (int i = 0; i < max_bits; i++)
    {
        int j = 0;
        int count = size;

        while (j < count)
        {
            if (((*a)->end_index >> i) & 1)
                ra(a);  // bit = 1 → ruota in fondo
            else
                pb(a, b); // bit = 0 → push in b
            j++;
        }

        while (*b)
            pa(a, b);
    }
}


// Funzione di insertion sort per l'ordinamento finale
void sort_remaining(t_stack **stack_a, t_stack **stack_b)
{
    // Se ci sono ancora pochi elementi in stack_b o stack_a, usa l'insertion sort
    t_stack *temp;
    while (*stack_a)
    {
        temp = *stack_a;
        while (temp && temp->next && temp->value > temp->next->value)
        {
            swap_stack(stack_a);
            temp = *stack_a;
        }
        push_stack(stack_a, stack_b);
    }
}

// Funzione di test per push_swap
int main()
{
    t_stack *stack_a = create_stack(5);
    stack_a->next = create_stack(1);
    stack_a->next->next = create_stack(4);
    stack_a->next->next->next = create_stack(2);
    stack_a->next->next->next->next = create_stack(3);

    t_stack *stack_b = NULL;

    push_swap(&stack_a, &stack_b);

    // Stampa l'ordinamento finale
    t_stack *current = stack_a;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    return 0;
}

// // Median of Three: Find pivot as the median of the first, middle, and last elements
// // RETURNS INDEXES NOT ELEMENTS
// int median_3(t_stack *stack, int low, int high) {
//     int f_idx = low;
//     int m_idx = (high - low) / 2;
//     int l_idx = high - 1;

//     int *first = (int*)get(stack, f_idx);               // First element
//     int *middle = (int*)get(stack, m_idx);              // Middle element
//     int *last = (int*)get(stack, l_idx);                // Last element

//     if (*first > *middle) {
//         if (*first < *last) return f_idx;
//         else if (*middle > *last) return m_idx;
//         else return l_idx;
//     } else {
//         if (*middle < *last) return m_idx;
//         else if (*first > *last) return f_idx;
//         else return l_idx;
//     }
// }

// // Partition the stack based on pivot (INDEX)
// int partition(t_stack **a, t_stack **b, int low, int high) {
//     int p_idx = median_3(*a, low, high);  // Use median of three as pivot
//     int *pivot = (int*)get(a, p_idx);
//     int i = low;
//     // Move elements smaller than pivot to b
//     while (i < high) {
//         if (*(int*)get(a, i) <= *(int*)get(a, p_idx)) {
//             swap_stack(a); //a[i], a[pivot]
//             p_idx++;
//         }
//         else {
//             push_stack(a, b); //a[pivot], get(pivot)
//         }
//         i++;
//     }
//     swap_stack(a); // a[p_idx], *pivot
//     return p_idx;
// }

// // Recursively sort the stack using quicksort-like partitioning
// void quick_sort(t_stack **a, t_stack **b, int low, int high) {
//     int p_index;
//     if (is_empty_stack(*a)) return; // Base case: If stack is empty, no sorting needed

//     if (low < high) {
//         p_index = partition(a, b, low, high); // Partition the stack into two parts

//         // Recursively sort the two parts
//         quick_sort(a, b, low, p_index - 1);   // Recursively sort a
//         quick_sort(b, a, p_index + 1, high);   // Recursively sort b and merge back into stackA    
//     }
// }