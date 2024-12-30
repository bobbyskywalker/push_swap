/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:39:25 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 21:22:15 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// edge case: swapping if there are only 2 elems in stack
void	swap_2_elems(t_stack **stack, t_stack *tmp)
{
	if (tmp != *stack)
	{
		(*stack)->next = tmp->next;
		tmp->next->prev = *stack;
		tmp->next = *stack;
		tmp->prev = (*stack)->prev;
		(*stack)->prev->next = tmp;
		(*stack)->prev = tmp;
		*stack = tmp;
	}
}

void	swap_ab(t_stack **stack, char id)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || (*stack)->next == *stack)
		return ;
	tmp = (*stack)->next;
	if (get_stack_size(stack) == 2)
	{
		swap_2_elems(stack, tmp);
		return ;
	}
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
