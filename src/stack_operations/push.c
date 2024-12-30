/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:44:03 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 17:50:28 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_push(t_stack **stack_from, t_stack **stack_to, t_stack *tmp_node)
{
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
	}
	else
	{
		tmp_node->next = *stack_to;
		tmp_node->prev = (*stack_to)->prev;
		(*stack_to)->prev->next = tmp_node;
		(*stack_to)->prev = tmp_node;
	}
	*stack_to = tmp_node;
}

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp_node;

	if (!(*stack_from))
		return ;
	tmp_node = *stack_from;
	do_push(stack_from, stack_to, tmp_node);
}
