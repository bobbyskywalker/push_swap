#include "../../includes/push_swap.h"

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