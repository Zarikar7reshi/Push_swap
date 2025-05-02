#include "stack.h"

t_stack	*init_stack(char name)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	stack->name = name;
	return (stack);
}

int	is_empty_stack(t_stack *stack)
{
	return (stack->head == NULL || stack->size == 0);
}

void	free_stack(t_stack **stack)
{
	ft_lstclear(&(*stack)->head, free);
	(*stack)->size = 0;
	free(*stack);
}
