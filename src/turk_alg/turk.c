/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:17:56 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 14:50:32 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    get_prices(t_stack **stack_a, t_stack **stack_b)
{
    int size;
    int i;
    t_stack *tmp;

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

t_stack *find_cheapest(t_stack **stack_a)
{
    t_stack *cheapest;
    t_stack *tmp;

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

void    push_all_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest_node;
    
    push(stack_a, stack_b, 'b');
    push(stack_a, stack_b, 'b');
    while (get_stack_size(stack_a) > 3)
    {
        get_targets(stack_a, stack_b);
        get_prices(stack_a, stack_b);
        cheapest_node = find_cheapest(stack_a);
        rotate_best(stack_a, stack_b, cheapest_node);
        push(stack_a, stack_b, 'b');
    }
}