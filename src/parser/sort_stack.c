/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:36:10 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 20:17:26 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_stack_size(t_stack **head)
{
	int				size;
	t_stack			*tmp;

	size = 1;
	if (!head || !(*head))
		return (0);
	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp == *head)
			break ;
		size++;
	}
	return (size);
}

void	create_arr(t_stack **stack, int *arr, int size)
{
	int		i;
	t_stack	*current;

	if (!arr)
		return ;
	current = *stack;
	i = 0;
	while (i < size)
	{
		*arr = current->value;
		current = current->next;
		arr++;
		i++;
	}
}

// selection sort d*_*b
void	sort_arr(int *arr, int len)
{
	int	min;
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		min = i;
		j = i + 1;
		while (j < len)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
		i++;
	}
}

void	update_stack(t_stack **stack, int *arr, int size)
{
	t_stack	*current;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		current = *stack;
		while (j < size)
		{
			if (arr[i] == current->value)
				current->value = i;
			current = current->next;
			j++;
		}
		i++;
	}
}

// simplified dll to work on the "indices" based off a position
// in a sorted list, in order to work with radix/turk alg
void	simplify_stack(t_stack **stack_a)
{
	int	*arr;
	int	size;

	size = get_stack_size(stack_a);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return ;
	create_arr(stack_a, arr, size);
	sort_arr(arr, size);
	update_stack(stack_a, arr, size);
	free(arr);
	arr = NULL;
}
