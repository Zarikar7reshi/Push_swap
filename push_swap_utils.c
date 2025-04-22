#include "push_swap.h"

// swap first and second
void swap_stack(t_stack **stack)
{
    if ((*stack)->size < 2)
        return ;
    t_list *first;
    t_list *second;

    first = (*stack)->head;
    second = first->next;
    first->next = second->next;
    second->next = first;
    (*stack)->head = second;
}

// push first b to a
void push_stack(t_stack **to, t_stack **from)
{
    void *content;

    if ((*from)->size == 0)
        return ;
    content = pop(from);
    push(to, content);
}

// first becomes last
void rotate_stack(t_stack **stack)
{
    void *content;
    if ((*stack)->size < 2)
        return ;
    content = pop(stack);
    push_back(stack, content);
}

// last becomes first
void reverse_rotate_stack(t_stack **stack)
{
    t_list *second_last;
    t_list *last;

    if ((*stack)->size < 2)
        return ;
    last = ft_lstlast((*stack)->head);
    second_last = (*stack)->head;
    while (second_last->next != last) 
        second_last = second_last->next;
    second_last->next = NULL;
    push(stack, last->content);
    free(last);
}