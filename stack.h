#include "./printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

// each t_list.content is a t_stacknode (allocation required)
typedef struct s_stack {
    t_list *head;
    size_t size;
    char name;
}   t_stack;

typedef struct s_stacknode {
	int value;
	int end_index;
}	t_stacknode;

int is_empty_stack(t_stack *stack);
t_stack *init_stack(char name);
void free_stack(t_stack **stack);

void push_node(t_stack **stack, t_list *node);
void push_back_node(t_stack **stack, t_list *node);
t_list *pop_node(t_stack **stack);
t_list *pop_last_node(t_stack **stack);

// high-level primitives (work on content)
void push(t_stack **stack, void *content);
//void push_back(t_stack **stack, void *content);
void *pop(t_stack **stack);
//void *peek(t_stack *stack);

void assign_end_indices(t_stack **stack);
// void find_index_from_value(t_stack **stack, t_list **curr, int *arr);
// void bubble_sort(int size, int **arr);
