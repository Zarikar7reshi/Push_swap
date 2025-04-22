#include "./printf/libft/libft.h"
#include <stdio.h>

typedef struct s_stack {
    t_list *head;
    size_t size;
    int end_index;
    char name;
} t_stack;

int is_empty_stack(t_stack *stack);
void init_stack(t_stack **stack, char name);
void free_stack(t_stack **stack);
void push(t_stack **stack, void *content);
void push_back(t_stack **stack, void *content);
void *pop(t_stack **stack);
void *peek(t_stack *stack);
void *get(t_stack *stack, int index);