#include "stack.h"

t_list *pop_node(t_stack **stack)
{
    if (!stack || !*stack || is_empty_stack(*stack))
        return NULL;

    t_list *node = (*stack)->head;
    (*stack)->head = node->next;
    node->next = NULL;
    (*stack)->size--;

    return node;
}

void push_node(t_stack **stack, t_list *node)
{
    if (!stack || !node)
        return;

    node->next = (*stack)->head;
    (*stack)->head = node;
    (*stack)->size++;
}

void push_back_node(t_stack **stack, t_list *node)
{
    if (!stack || !node)
        return;

    // If the stack is empty, the node becomes the head
    if ((*stack)->size == 0) {
        (*stack)->head = node;
    } else {
        // Traverse the stack to find the last node
        t_list *current = (*stack)->head;
        while (current->next) {
            current = current->next;
        }
        // Link the last node to the new node
        current->next = node;
    }

    // The new node's next is NULL, since it will now be the last node
    node->next = NULL;

    // Increment the stack size
    (*stack)->size++;
}

t_list *pop_last_node(t_stack **stack)
{
    if (!stack || (*stack)->size < 2)
        return NULL;

    t_list *current = (*stack)->head;
    t_list *prev = NULL;

    // Traverse to the last node
    while (current->next) {
        prev = current;
        current = current->next;
    }

    // Now `current` is the last node
    if (prev) {
        prev->next = NULL;  // Detach the last node
    }

    // Decrease stack size
    (*stack)->size--;

    // Return the last node
    return current;
}


// WARNING: these primitives are high-level since they work with node contents

void *pop(t_stack **stack)
{
    t_list *node_tmp;
    void *content;

    if (!stack || !*stack || is_empty_stack(*stack))
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
        // free(node_tmp);
        (*stack)->size--;
        // ft_printf("pop\n");
        return (content);
    }
}

void push(t_stack **stack, void *content)
{
    t_list *new_node;

    new_node = ft_lstnew(content);
    if (!new_node)
        // return((void)ft_printf("Stack overflow (memory allocation failed)\n"));
        return((void)ft_printf("Stack overflow (memory allocation failed)\n"));
    ft_lstadd_front(&(*stack)->head, new_node);
    (*stack)->size++;
    // ft_printf("push\n");
}

// void *peek(t_stack *stack)
// {
//     if (is_empty_stack(stack))
//     {
//         // ft_printf("Stack empty\n");
//         ft_printf("Stack empty\n");
//         return (NULL);
//     }    
//     return (stack->head->content);
// }

// void push_back(t_stack **stack, void *content)
// {
//     t_list *new_node;

//     new_node = ft_lstnew(content);
//     if (!new_node)
//         // return((void)ft_printf("Stack overflow (memory allocation failed)\n"));
//         return((void)ft_printf("Stack overflow (memory allocation failed)\n"));
//     ft_lstadd_back(&(*stack)->head, new_node);
//     (*stack)->size++;
// }

// void *get(t_stack *stack, int index) {
//     if (stack->head == NULL) {
//         return NULL; // Return -1 if stack is empty
//     }

//     t_list *current = stack->head;
//     int currentIndex = 0;

//     // Traverse the stack to find the node at the given index
//     while (current != NULL) {
//         if (currentIndex == index) {
//             return current->content; // Return the data at the found index
//         }
//         current = current->next;
//         currentIndex++;
//     }

//     return NULL; // Return -1 if the index is out of bounds
// }
