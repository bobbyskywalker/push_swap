/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:39:20 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 19:38:36 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// the first element already has a ptr to the last node so thats all :))
void	rotate_up(t_stack **stack, char id)
{
	if (!stack || !(*stack) || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
	if (id == 'a')
		ft_printf("ra\n");
	else if (id == 'b')
		ft_printf("rb\n");
	else
		return ;
}

void	rotate_down(t_stack **stack, char id)
{
	if (!stack || !(*stack) || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
	if (id == 'a')
		ft_printf("rra\n");
	else if (id == 'b')
		ft_printf("rrb\n");
	else
		return ;
}

void	rotate_both_up(t_stack **stack_a, t_stack **stack_b)
{
	rotate_up(stack_a, 'x');
	rotate_up(stack_b, 'x');
	ft_printf("rr\n");
}

void	rotate_both_down(t_stack **stack_a, t_stack **stack_b)
{
	rotate_down(stack_a, 'x');
	rotate_down(stack_b, 'x');
	ft_printf("rrr\n");
}
