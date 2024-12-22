#include "../../includes/push_swap.h"

void	swap_ab(t_stack **stack)
{
    t_stack	*tmp;
    t_stack *last;

    if (!(*stack) || (*stack)->next == *stack)
        return ;
    tmp = (*stack)->next;
    last = (*stack)->prev;
    (*stack)->next = tmp->next;
    (*stack)->next->prev = *stack;
    tmp->next = *stack;
    tmp->prev = last;
    last->next = tmp;
    (*stack)->prev = tmp;
    *stack = tmp;
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
    swap_ab(stack_a);
    swap_ab(stack_b);
}