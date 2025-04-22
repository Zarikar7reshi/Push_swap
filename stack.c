#include "stack.h"

void init_stack(t_stack **stack, char name)
{
    (*stack)->head = NULL;
    (*stack)->size = 0;
    (*stack)->name = name;
}

int is_empty_stack(t_stack *stack)
{
    return (stack->size == 0);
}

void free_stack(t_stack **stack)
{
    ft_lstclear(&(*stack)->head, free);
    (*stack)->size = 0;
}

void *pop(t_stack **stack)
{
    t_list *node_tmp;
    void *content;

    if (is_empty_stack(*stack))
    {
        // ft_printf("Stack underflow\n");
        printf("Stack underflow\n");
        return (NULL);
    }
    else
    {
        node_tmp = (*stack)->head;
        (*stack)->head = (*stack)->head->next;
        content = node_tmp->content;
        free(node_tmp);
        (*stack)->size--;
        return (content);
    }
}

void push(t_stack **stack, void *content)
{
    t_list *new_node;

    new_node = ft_lstnew(content);
    if (!new_node)
        // return((void)ft_printf("Stack overflow (memory allocation failed)\n"));
        return((void)printf("Stack overflow (memory allocation failed)\n"));
    ft_lstadd_front(&(*stack)->head, new_node);
    (*stack)->size++;
}

void *peek(t_stack *stack)
{
    if (is_empty_stack(stack))
    {
        // ft_printf("Stack empty\n");
        printf("Stack empty\n");
        return (NULL);
    }    
    return (stack->head->content);
}

void push_back(t_stack **stack, void *content)
{
    t_list *new_node;

    new_node = ft_lstnew(content);
    if (!new_node)
        // return((void)ft_printf("Stack overflow (memory allocation failed)\n"));
        return((void)printf("Stack overflow (memory allocation failed)\n"));
    ft_lstadd_back(&(*stack)->head, new_node);
    (*stack)->size++;
}

void *get(t_stack *stack, int index) {
    if (stack->head == NULL) {
        return NULL; // Return -1 if stack is empty
    }

    t_list *current = stack->head;
    int currentIndex = 0;

    // Traverse the stack to find the node at the given index
    while (current != NULL) {
        if (currentIndex == index) {
            return current->content; // Return the data at the found index
        }
        current = current->next;
        currentIndex++;
    }

    return NULL; // Return -1 if the index is out of bounds
}
