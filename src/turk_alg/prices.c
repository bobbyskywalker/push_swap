/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prices.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:12:13 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 19:13:11 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	get_prices(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		i;
	t_stack	*tmp;

	size = get_stack_size(stack_a);
	tmp = *stack_a;
	i = 0;
	while (i != get_stack_size(stack_a))
	{
		tmp->price = calc_p_ra_rb(stack_a, stack_b, tmp);
		if (calc_p_ra_rrb(stack_a, stack_b, tmp) < tmp->price)
			tmp->price = calc_p_ra_rrb(stack_a, stack_b, tmp);
		if (calc_p_rra_rb(stack_a, stack_b, tmp) < tmp->price)
			tmp->price = calc_p_rra_rb(stack_a, stack_b, tmp);
		if (calc_p_rra_rrb(stack_a, stack_b, tmp) < tmp->price)
			tmp->price = calc_p_rra_rrb(stack_a, stack_b, tmp);
		tmp = tmp->next;
		i++;
	}
}

t_stack	*find_cheapest(t_stack **stack_a)
{
	t_stack	*cheapest;
	t_stack	*tmp;

	cheapest = *stack_a;
	tmp = (*stack_a)->next;
	while (tmp != (*stack_a))
	{
		if (cheapest->price > tmp->price)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}