/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:17:56 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 20:26:15 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_all_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	while (get_stack_size(stack_a) > 3)
	{
		get_targets(stack_a, stack_b);
		get_prices(stack_a, stack_b);
		cheapest_node = find_cheapest(stack_a);
		rotate_best(stack_a, stack_b, cheapest_node);
		push(stack_a, stack_b, 'b');
	}
}

void    push_back_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *max;
    
    max = find_max(stack_b);
    while (*stack_b != max)
        rotate_down(stack_b, 'b');
    while (*stack_b)
        push(stack_b, stack_a, 'a');
}
