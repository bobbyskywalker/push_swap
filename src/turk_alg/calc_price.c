/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:52:14 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 15:31:55 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

// price calculations for each operation combinations
int	calc_p_ra_rb(t_stack **stack_a, t_stack **stack_b, t_stack *item)
{
	int	price;

	price = find_pos(stack_a, item->value);
	if (find_pos(stack_b, item->target->value) > price)
		price = find_pos(stack_b, item->target->value);
	return (price);
}

int	calc_p_ra_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *item)
{
	int	price_a;
	int	price_b;

	price_a = find_pos(stack_a, item->value);
	price_b = get_stack_size(stack_b) - find_pos(stack_b, item->target->value);
	return (price_a + price_b);
}

int	calc_p_rra_rb(t_stack **stack_a, t_stack **stack_b, t_stack *item)
{
	int	price_a;
	int	price_b;

	price_a = get_stack_size(stack_a) - find_pos(stack_a, item->value);
	price_b = find_pos(stack_b, item->target->value);
	return (price_a + price_b);
}

int	calc_p_rra_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *item)
{
	int	price;

	price = get_stack_size(stack_a) - find_pos(stack_a, item->value);
	if (get_stack_size(stack_b) - find_pos(stack_b, item->target->value) > price)
		price = get_stack_size(stack_b) - find_pos(stack_b, item->target->value);
	return (price);
}
