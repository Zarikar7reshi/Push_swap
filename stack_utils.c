#include "stack.h"

t_stack *init_stack(char name)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->head = NULL;
    stack->size = 0;
    stack->name = name;
    return (stack);
}

int is_empty_stack(t_stack *stack)
{
    return (stack->head == NULL || stack->size == 0 );
}

void free_stack(t_stack **stack)
{
    ft_lstclear(&(*stack)->head, free);
    (*stack)->size = 0;
}

void assign_end_indices(t_stack **stack)
{
    int size = (*stack)->size;
    int *arr = malloc(sizeof(int) * size);
    t_list *curr = (*stack)->head;

    for (int i = 0; i < size && curr != NULL; i++)
    {
        arr[i] = ((t_stacknode *)curr->content)->value;
        curr = curr->next;
    }
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
    curr = (*stack)->head;
    while (curr)
    {
        for (int i = 0; i < size; i++)
        {
            if (((t_stacknode *)curr->content)->value == arr[i])
            {
                ((t_stacknode *)curr->content)->end_index = i;
                break;
            }
        }
        curr = curr->next;
    }
    free(arr);
}