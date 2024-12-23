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
        if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN || (ft_atoi(argv[i]) == 0 && argv[i][0] != '0'))
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2 || check_args(argv) || is_duplicate(argv)) {
        write(2, "Error\n", 6);
        return 1;
    }
    stack_a = NULL;
    stack_b = NULL;

    parse_stack(&stack_a, argv);
    simplify_stack(&stack_a);

    // alg func goes here

    free_stack(&stack_a);
    free_stack(&stack_b);
    return 0;
}
