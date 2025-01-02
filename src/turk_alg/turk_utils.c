/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:32:19 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/02 16:58:05 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	min = (*stack)->value;
	tmp = (*stack)->next;
	while (tmp != *stack)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	max = (*stack)->value;
	tmp = (*stack)->next;
	while (tmp != *stack)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	is_stack_sorted(t_stack **stack, int size)
{
	int	v;
	int	i;

	i = 0;
	v = (*stack)->value;
	(*stack) = (*stack)->next;
	while (i < size - 1)
	{
		if (v > (*stack)->value)
			return (0);
		v = (*stack)->value;
		(*stack) = (*stack)->next;
		i++;
	}
	return (1);
}

int	find_pos(t_stack **stack, int val)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp->value != val)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

// node param: node from stack a which
// we are assigning a stack b target to
// (to place above)
t_stack		*find_target(t_stack **stack_b, t_stack *node)
{
	t_stack	*min;
	t_stack	*max;

	min = find_min(stack_b);
	max = find_max(stack_b);
	if (node->value < min || node->value > max)
		return (max);
	while ((node->value <= (*stack_b)->value)
		&& node->value < (*stack_b)->prev->value)
		(*stack_b) = (*stack_b)->next;
	return (stack_b);
}
