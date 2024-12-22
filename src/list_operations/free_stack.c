#include "../../includes/push_swap.h"

void free_stack(t_stack **stack)
{
    t_stack *tmp;
    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}