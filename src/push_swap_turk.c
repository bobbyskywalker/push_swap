/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:34:03 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 19:50:37 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if ((find_min(stack_a) == (*stack_a)->value))
	{
		rotate_down(stack_a, 'a');
		swap_ab(stack_a, 'a');
	}
	else if ((find_max(stack_a) == (*stack_a)->value))
	{
		rotate_up(stack_a, 'a');
		if (!is_stack_sorted(stack_a, 3))
			swap_ab(stack_a, 'a');
	}
	else
	{
		if (find_pos(stack_a, find_max(stack_a)) == 1)
			rotate_down(stack_a, 'a');
		else
			swap_ab(stack_a, 'a');
	}
}
