#include "../../includes/push_swap.h"

int error_handler(int argc, char **argv, int i)
{
    if (argc < 2)
        return (1);
    if (check_args(argv, i) || is_duplicate(argv) || i == -1) {
        if (argc == 2)
            ft_arr2d_free(argv);
        write(2, "Error\n", 6);
        return (1);
    }
    return (0);
}