/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:52:14 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/02 17:01:43 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    get_targets(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current;
    int     i;
    
    current = (*stack_a);
    i = 0;
    while(i < get_stack_size(stack_a))
    {
        current->target = find_target(stack_b, current);
        i++;
    }
}