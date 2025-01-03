/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:34:03 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 14:40:09 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (find_min(stack_a)->value == (*stack_a)->value)
	{
		rotate_down(stack_a, 'a');
		swap_ab(stack_a, 'a');
	}
	else if (find_max(stack_a)->value == (*stack_a)->value)
	{
		rotate_up(stack_a, 'a');
		if (!is_stack_sorted(stack_a, 3))
			swap_ab(stack_a, 'a');
	}
	else
	{
		if (find_pos(stack_a, find_max(stack_a)->value) == 1)
			rotate_down(stack_a, 'a');
		else
			swap_ab(stack_a, 'a');
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	push_all_b(stack_a, stack_b);
	sort_three(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	(void)stack_b;
	if (size == 2 && (*stack_a)->value > (*stack_a)->next->value)
		swap_ab(stack_a, 'a');
	if (size == 3)
		sort_three(stack_a);
	else
		sort_big(stack_a, stack_b);
}
