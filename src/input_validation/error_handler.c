/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:19:44 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 17:26:14 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	error_handler(int argc, char **argv, int i)
{
	if (argc < 2)
		return (1);
	if (check_args(argv, i) || is_duplicate(argv) || i == -1)
	{
		if (argc == 2)
			ft_arr2d_free(argv);
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
