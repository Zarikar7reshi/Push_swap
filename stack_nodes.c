#include "stack.h"

t_list	*pop_node(t_stack **stack)
{
	t_list	*node;

	if (!stack || is_empty_stack(*stack))
		return (NULL);
	node = (*stack)->head;
	(*stack)->head = node->next;
	node->next = NULL;
	(*stack)->size--;
	return (node);
}

void	push_node(t_stack **stack, t_list *node)
{
	if (!stack || !node)
		return ;
	node->next = (*stack)->head;
	(*stack)->head = node;
	(*stack)->size++;
}

void	push_back_node(t_stack **stack, t_list *node)
{
	t_list	*current;

	if (!stack || !node)
		return ;
	if ((*stack)->size == 0)
		(*stack)->head = node;
	else
	{
		current = (*stack)->head;
		while (current->next)
			current = current->next;
		current->next = node;
	}
	node->next = NULL;
	(*stack)->size++;
}

t_list	*pop_last_node(t_stack **stack)
{
	t_list	*current;
	t_list	*prev;

	if (!stack || is_empty_stack(*stack))
		return (NULL);
	current = (*stack)->head;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	(*stack)->size--;
	return (current);
}
