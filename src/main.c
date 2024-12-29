#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int			size;
    int         i;

    i = format_input(argc, &argv);
    if (error_handler(argc, argv, i))
        return (1);
    stack_a = NULL;
    stack_b = NULL;
    parse_stack(&stack_a, argv, i);
    size = get_stack_size(&stack_a);
    if (is_sorted(&stack_a, size))
    {
        free_stack(&stack_a);
        if (argc == 2)
            ft_arr2d_free(argv);
        return (0);
    }
    simplify_stack(&stack_a);
    push_swap_radix(&stack_a, &stack_b, size);
    free_stack(&stack_a);
    free_stack(&stack_b);
    if (argc == 2)
        ft_arr2d_free(argv);
    return (0);
}
