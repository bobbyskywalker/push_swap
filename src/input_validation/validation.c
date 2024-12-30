/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:20:03 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 18:30:46 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	check_args(char **argv, int i)
{
	long	val;

	while (argv[i])
	{
		ft_safe_atoi(argv[i], &val);
		if (val > (long)INT_MAX || val < (long)INT_MIN || (val == 0
				&& argv[i][0] != '0'))
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(t_stack **stack, int size)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *stack;
	while (i < size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
