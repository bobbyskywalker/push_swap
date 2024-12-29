#include "../../includes/push_swap.h"

int error_handler(int argc, char **argv, int i)
{
    if (argc < 2)
        return (1);
    if (check_args(argv) || is_duplicate(argv) || i == -1) {
        write(2, "Error\n", 6);
        return (1);
    }
    return (0);
}