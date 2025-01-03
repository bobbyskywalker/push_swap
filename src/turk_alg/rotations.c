/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:06:55 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 14:22:09 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// func to select and perform the best rotation
// based off price-checks
static void	rotate_ra_rb(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	while (*stack_a != node && *stack_b != node->target)
		rotate_both_up(stack_a, stack_b);
	while (*stack_a != node)
		rotate_up(stack_a, 'a');
	while (*stack_b != node->target)
		rotate_up(stack_b, 'b');
	(*stack_a)->price = 0;
}

static void	rotate_rra_rb(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	while (*stack_a != node)
		rotate_down(stack_a, 'a');
	while (*stack_b != node->target)
		rotate_up(stack_b, 'b');
	(*stack_a)->price = 0;
}

static void	rotate_ra_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	while (*stack_a != node)
		rotate_up(stack_a, 'a');
	while (*stack_b != node->target)
		rotate_down(stack_b, 'b');
	(*stack_a)->price = 0;
}

static void	rotate_rra_rrb(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	while (*stack_a != node && *stack_b != node->target)
		rotate_both_down(stack_a, stack_b);
	while (*stack_a != node)
		rotate_down(stack_a, 'a');
	while (*stack_b != node->target)
		rotate_down(stack_b, 'b');
	(*stack_a)->price = 0;
}

void	rotate_best(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int	price;

	price = node->price;
	if (price == calc_p_ra_rb(stack_a, stack_b, node))
		rotate_ra_rb(stack_a, stack_b, node);
	else if (price == calc_p_ra_rrb(stack_a, stack_b, node))
		rotate_ra_rrb(stack_a, stack_b, node);
	else if (price == calc_p_rra_rb(stack_a, stack_b, node))
		rotate_rra_rb(stack_a, stack_b, node);
	else if (price == calc_p_rra_rrb(stack_a, stack_b, node))
		rotate_rra_rrb(stack_a, stack_b, node);
	else
		printf("u fucked up lol");
}
