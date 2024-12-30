/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:58:56 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/30 19:42:30 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Section: INCLUDES
# include "../lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// SECTION: DLL
// a doubly linked list node prototype & library
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack				*create_node(int content);
t_stack				*get_last(t_stack *stack);
void				lstadd_front(t_stack **stack, t_stack *new);
void				lstadd_end(t_stack **stack, t_stack *new);
void				rm_node(t_stack **stack, t_stack *node);
void				free_stack(t_stack **stack);

// SECTION: stack utils
void				parse_stack(t_stack **stack, char **argv, int i);
int					get_stack_size(t_stack **head);
void				simplify_stack(t_stack **stack_a);

// SECTION: stack operations
void				swap_ab(t_stack **stack, char id);
void				swap_both(t_stack **stack_a, t_stack **stack_b);
void				push(t_stack **stack_from, t_stack **stack_to, char id);
void				rotate_up(t_stack **stack, char id);
void				rotate_down(t_stack **stack, char id);
void				rotate_both_up(t_stack **stack_a, t_stack **stack_b);
void				rotate_both_down(t_stack **stack_a, t_stack **stack_b);

// SECTION: input validation
int					error_handler(int argc, char **argv, int i);
int					format_input(int argc, char ***argv);
int					is_duplicate(char **argv);
int					check_args(char **argv, int i);
int					is_sorted(t_stack **stack, int size);
int					ft_safe_atoi(const char *str, long *result);


// SECTION: TURK'S ALGORITHM
void				sort_three(t_stack **stack_a);
int					find_min(t_stack **stack);
int					find_max(t_stack **stack);
int					is_stack_sorted(t_stack **stack, int size);
int					find_pos(t_stack **stack, int val);


// MAIN ALGORITHM FUNC
void				push_swap_radix(t_stack **stack_a, t_stack **stack_b,
						int size);

#endif