/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:39:25 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 19:41:31 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_ab(t_stack **stack, char id)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || (*stack)->next == *stack)
		return ;
	tmp = (*stack)->next;
	last = (*stack)->prev;
	(*stack)->next = tmp->next;
	(*stack)->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = last;
	last->next = tmp;
	(*stack)->prev = tmp;
	*stack = tmp;
	if (id == 'a')
		ft_printf("sa\n");
	else if (id == 'b')
		ft_printf("sb\n");
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap_ab(stack_a, 'x');
	swap_ab(stack_b, 'x');
	ft_printf("ss\n");
}
