/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:53:19 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 19:00:14 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	int		i;

	i = format_input(argc, &argv);
	if (error_handler(argc, argv, i))
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	parse_stack(&stack_a, argv, i);
	size = get_stack_size(&stack_a);
	if (is_sorted(&stack_a, size))
	{
		free_stack(&stack_a);
		if (argc == 2)
			ft_arr2d_free(argv);
		return (0);
	}
	simplify_stack(&stack_a);
	// push_swap_radix(&stack_a, &stack_b, size);
	push_swap(&stack_a, &stack_b, size);
	free_stacks(&stack_a, &stack_b);
	if (argc == 2)
		ft_arr2d_free(argv);
	return (0);
}
