/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:54:49 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 17:55:21 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// radix sort algorithm (for big stacks only)
void	push_swap_radix(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	cur_num;

	max_num = size - 1;
	max_bits = 0;
	i = 0;
	j = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			cur_num = (*stack_a)->value;
			if (((cur_num >> i) & 1) == 1)
			{
				rotate_up(stack_a);
				ft_printf("ra\n");
			}
			else
			{
				push(stack_a, stack_b);
				ft_printf("pb\n");
			}
			j++;
		}
		while ((*stack_b))
		{
			push(stack_b, stack_a);
			ft_printf("pa\n");
		}
		i++;
	}
}
