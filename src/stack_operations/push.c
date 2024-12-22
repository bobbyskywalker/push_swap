#include "../../includes/push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp_node;

	if (!(*stack_from))
		return ;
	tmp_node = *stack_from;
	if (*stack_from == (*stack_from)->next)
		*stack_from = NULL;
	else
	{
		(*stack_from)->next->prev = (*stack_from)->prev;
		(*stack_from)->prev->next = (*stack_from)->next;
		*stack_from = (*stack_from)->next;
	}

	if (!(*stack_to))
	{
		tmp_node->next = tmp_node;
		tmp_node->prev = tmp_node;
		*stack_to = tmp_node;
	}
	else
	{
		tmp_node->next = *stack_to;
		tmp_node->prev = (*stack_to)->prev;
		(*stack_to)->prev->next = tmp_node;
		(*stack_to)->prev = tmp_node;
		*stack_to = tmp_node;
	}
}

