/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:11:58 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 18:59:57 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// node param: node from stack a which
// we are assigning a stack b target to
// (to place above)

t_stack	*find_target(t_stack **stack_b, t_stack *node)
{
	t_stack	*cur;
	t_stack	*best_target;
	int		best_diff;
	int		diff;

	best_target = NULL;
	best_diff = INT_MIN;
	cur = *stack_b;
	if (!cur)
		return (NULL);
	while (cur)
	{
		diff = cur->value - node->value;
		if (diff <= 0 && diff > best_diff)
		{
			best_diff = diff;
			best_target = cur;
		}
		cur = cur->next;
		if (cur == *stack_b)
			break ;
	}
	if (!best_target)
		best_target = find_max(stack_b);
	return (best_target);
}

void	get_targets(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		i;
	int		stack_size;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	stack_size = get_stack_size(stack_a);
	current = *stack_a;
	i = 0;
	while (i < stack_size)
	{
		current->target = find_target(stack_b, current);
		current = current->next;
		if (current == *stack_a)
			break ;
		i++;
	}
}
