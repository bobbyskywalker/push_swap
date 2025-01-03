/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:11:58 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 16:14:12 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// node param: node from stack a which
// we are assigning a stack b target to
// (to place above)
t_stack		*find_target(t_stack **stack_b, t_stack *node)
{
	t_stack *min;
	t_stack	*max;

	min = find_min(stack_b);
	max = find_max(stack_b);
	if (node->value < min->value || node->value > max->value)
		return (max);
	while ((node->value <= (*stack_b)->value)
		&& node->value < (*stack_b)->prev->value)
		(*stack_b) = (*stack_b)->next;
	return (*stack_b);
}

void	get_targets(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		i;

	current = (*stack_a);
	i = 0;
	while (i < get_stack_size(stack_a))
	{
		current->target = find_target(stack_b, current);
		i++;
		current = current->next;
	}
}
