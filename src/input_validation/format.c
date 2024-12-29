#include "../../includes/push_swap.h"

// function to check the way the args were passed into the program
// returns 1 on: modifying not needed
// returns 0 on: modified argv
// the i variable is crucial to the parse_stack() func
// it is passed to the error_handler() to verify correctness
int format_input(int argc, char ***argv)
{
    char **split_argv;

    if (argc == 2)
    {
        split_argv = ft_split((*argv)[1], ' ');
        if (!split_argv)
            return (-1);
        *argv = split_argv;
        return (0);
    }
    return (1);
}