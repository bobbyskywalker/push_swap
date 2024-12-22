#include "../../includes/push_swap.h"
#include "../../lib/libft/libft.h"

void	swap_ab(t_stack **stack)
{
    t_stack	*tmp;

    if (!(*stack) || !(*stack)->next)
        return ;
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = *stack;
    *stack = tmp;
    ft_printf("sa\n");
}


void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
    swap_ab(stack_a);
    swap_ab(stack_b);
    ft_printf("ss\n");
}