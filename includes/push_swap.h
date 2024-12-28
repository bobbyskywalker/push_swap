#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Section: INCLUDES
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include "../lib/libft/libft.h"

// SECTION: DLL
// a doubly linked list node prototype & library
typedef struct s_stack
{
    int				value;
    struct s_stack  *next;
    struct s_stack  *prev;
}	t_stack;

t_stack	    *create_node(int content);
t_stack	    *get_last(t_stack *stack);
void        lstadd_front(t_stack **stack, t_stack *new);
void        lstadd_end(t_stack **stack, t_stack *new);
void        rm_node(t_stack **stack, t_stack *node);
void        free_stack(t_stack **stack);

// SECTION: stack utils
void         parse_stack(t_stack **stack, char **argv, int i);
int          get_stack_size(t_stack **head);
void         simplify_stack(t_stack **stack_a);

// SECTION: stack operations
void        swap_ab(t_stack **stack);
void        swap_both(t_stack **stack_a, t_stack **stack_b);
void        push(t_stack **stack_from, t_stack **stack_to);
void        rotate_up(t_stack **stack);
void        rotate_down(t_stack **stack);
void        rotate_both_up(t_stack **stack_a, t_stack **stack_b);
void        rotate_both_down(t_stack **stack_a, t_stack **stack_b);

// MAIN ALGORITHM FUNC
void        push_swap(t_stack **stack_a, t_stack **stack_b, int size);

#endif 