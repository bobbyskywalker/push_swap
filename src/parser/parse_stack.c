/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:35:37 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 17:39:02 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	parse_stack(t_stack **stack, char **argv, int i)
{
	t_stack	*node;

	while (argv[i])
	{
		node = create_node(ft_atoi(argv[i]));
		if (!node)
		{
			free_stack(stack);
			return ;
		}
		lstadd_end(stack, node);
		i++;
	}
}
