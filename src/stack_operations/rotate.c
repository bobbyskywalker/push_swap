#include "../../includes/push_swap.h"

// the first element already has a ptr to the last node so thats all :))
void rotate_up(t_stack **stack)
{
    if (!stack || !(*stack) || (*stack)->next == *stack)
        return;
    *stack = (*stack)->next;
}

void rotate_down(t_stack **stack)
{
    if (!stack || !(*stack) || (*stack)->next == *stack)
        return;
    *stack = (*stack)->prev;
}

void    rotate_both_up(t_stack **stack_a, t_stack **stack_b)
{
    rotate_up(stack_a);
    rotate_up(stack_b);
}

void    rotate_both_down(t_stack **stack_a, t_stack **stack_b)
{
    rotate_down(stack_a);
    rotate_down(stack_b);
}