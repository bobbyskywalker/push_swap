#include "../includes/push_swap.h"

void parse_stack(t_stack **stack, char **argv)
{
    t_stack *node;
    int 	i;

	i = 1;
    while (argv[i]) {
        node = create_node(ft_atoi(argv[i]));
        if (!node)
        {
            free_stack(stack);
            return;
        }
        lstadd_end(stack, node);
        i++; 
    }
}