/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:54:49 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 19:00:17 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// radix sort algorithm (for big stacks only)
int	get_max_bits(int size)
{
	int	max_num;
	int	max_bits;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	push_swap_radix(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	max_bits;
	int	i;
	int	j;
	int	cur_num;

	max_bits = get_max_bits(size);
	i = 0;
	j = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			cur_num = (*stack_a)->value;
			if (((cur_num >> i) & 1) == 1)
				rotate_up(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			j++;
		}
		while ((*stack_b))
			push(stack_b, stack_a, 'a');
		i++;
	}
}
