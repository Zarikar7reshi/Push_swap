#include "push_swap.h"

void check_duplicates(t_stack *stack)
{
    (void)stack;
}

// swap first and second
void swap_stack(t_stack **stack)
{
    if ((*stack)->size < 2)
        return;

    t_list *first = pop_node(stack);
    t_list *second = pop_node(stack);

    second->next = first;
    push_node(stack, second);
    push_node(stack, first);
}

// push first b to a
void push_stack(t_stack **from, t_stack **to)
{
    t_list *node = pop_node(from);
    if (node)
        push_node(to, node);
}

// first becomes last
void rotate_stack(t_stack **stack)
{
    if (!stack || (*stack)->size < 2)
        return;
    t_list *first = pop_node(stack);
    push_back_node(stack, first);
}

// last becomes first
void reverse_rotate_stack(t_stack **stack)
{
    if (!stack || (*stack)->size < 2)
        return;
    t_list *last = pop_last_node(stack);
    push_node(stack, last);
}


// void swap_stack(t_stack **stack)
// {
//     if ((*stack)->size < 2)
//         return ;
//     t_list *first;
//     t_list *second;

//     first = (*stack)->head;
//     second = first->next;
//     first->next = second->next;
//     second->next = first;
//     (*stack)->head = second;
// }

// void push_stack(t_stack **from, t_stack **to)
// {
//     void *content;

//     if (is_empty_stack(*from))
//         return ;
//     content = pop(from);
//     push(to, content);
// }

// void rotate_stack(t_stack **stack)
// {
//     void *content;
//     if ((*stack)->size < 2)
//         return ;
//     content = pop(stack);
//     push_back(stack, content);
// }

// void reverse_rotate_stack(t_stack **stack)
// {
//     t_list *second_last;
//     t_list *last;

//     if ((*stack)->size < 2)
//         return ;
//     last = ft_lstlast((*stack)->head);
//     second_last = (*stack)->head;
//     while (second_last->next != last) 
//         second_last = second_last->next;
//     second_last->next = NULL;
//     push(stack, last->content);
//     free(last);
// }