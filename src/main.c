#include "../includes/push_swap.h"

int is_duplicate(char **argv)
{
    int i;
    int j;

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

int     check_args(char **argv)
{
    int i;

    i = 1;
    while (argv[i])
    {
        //TODO: safer atoi
        if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN || (ft_atoi(argv[i]) == 0 && argv[i][0] != '0'))
            return (1);
        i++;
    }
    return (0);
}

int is_sorted(t_stack **stack, int size)
{
    int i;
    t_stack *current;

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

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char        **args_list;
    int			size;
    int         i;

    if (check_args(argv) || is_duplicate(argv)) {
        write(2, "Error\n", 6);
        return (1);
    }
    i = 1;
    if (argc == 2)
    {
        args_list = ft_split(argv[1], ' ');
        if (!argv[1])
        {
            free_2d(args_list);
            return (1);
        }
        i = 0;
    }
    stack_a = NULL;
    stack_b = NULL;
    parse_stack(&stack_a, argv, i);
    size = get_stack_size(&stack_a);
    if (is_sorted(&stack_a, size))
    {
        free_stack(&stack_a);
        return (0);
    }
    simplify_stack(&stack_a);
    push_swap(&stack_a, &stack_b, size);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
