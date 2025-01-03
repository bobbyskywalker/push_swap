/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:11:58 by agarbacz          #+#    #+#             */
/*   Updated: 2025/01/03 18:37:44 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// node param: node from stack a which
// we are assigning a stack b target to
// (to place above)
/* t_stack	*find_target(t_stack **stack_b, t_stack *node)
{
	t_stack	*min;
	t_stack	*max;

	min = find_min(stack_b);
	max = find_max(stack_b);
	if (node->value < min->value || node->value > max->value)
		return (max);
	while ((node->value <= (*stack_b)->value)
		&& node->value < (*stack_b)->prev->value)
		(*stack_b) = (*stack_b)->next;
	return (*stack_b);
} */

t_stack *find_target(t_stack **stack_b, t_stack *node)
{
    t_stack *cur;
    t_stack *best_target = NULL;
    int best_diff = INT_MIN; // Największa ujemna różnica (lub równa 0)

    cur = *stack_b;
    if (!cur)
        return NULL;

    do {
        int diff = cur->value - node->value;

        // Szukamy największej różnicy, która jest <= 0
        if (diff <= 0 && diff > best_diff)
        {
            best_diff = diff;
            best_target = cur;
        }

        cur = cur->next;
    } while (cur != *stack_b);

    // Jeśli nie znaleziono lepszego targetu, zwróć maksymalny element
    if (!best_target)
        best_target = find_max(stack_b);

    // printf("find_target: Node value = %d, Target value = %d\n",
    //        node->value, best_target->value);

    return best_target;
}


/* void	get_targets(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		i;

	current = (*stack_a);
	i = 0;
	while (i < get_stack_size(stack_a))
	{
		current->target = find_target(stack_b, current);
		i++;
		current = current->next;
	}
}
 */

void	get_targets(t_stack **stack_a, t_stack **stack_b)
{
    t_stack	*current;
    int		i;
    int		stack_size;

    if (!stack_a || !*stack_a || !stack_b || !*stack_b)
    {
        printf("ERROR: Null pointer in get_targets\n");
        return;
    }

    stack_size = get_stack_size(stack_a);
    current = *stack_a;

    for (i = 0; i < stack_size; i++)
    {
        current->target = find_target(stack_b, current);

        // Debug
        // if (current->target)
        // {
        //     printf("Set target: Node value = %d, Target value = %d\n",
        //            current->value, current->target->value);
        // }
        // else
        // {
        //     printf("ERROR: Target is NULL for node value = %d\n", current->value);
        // }

        current = current->next;

        // Zabezpieczenie dla cyklicznej listy
        if (current == *stack_a)
            break;
    }
}

