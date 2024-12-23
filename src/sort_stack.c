#include "../includes/push_swap.h"

int get_stack_size(t_stack **head)
{
    int size;
    t_stack *tmp;

    size = 1;
    if (!head || !(*head))
        return (0);
    tmp = *head;
    while (tmp)
    {
        tmp = tmp->next;
        if (tmp == *head)
            break;
        size++;
    }
    return (size);
}

// i: node tracker (not to break reference), j: indices index: 
void    sort_stack(int *indices, t_stack **stack, int size)
{
    int lowest;
    int i;
    int j;
    t_stack *tmp;

    tmp = *stack;
    i = 0;
    j = 0;
    lowest = tmp->value;
    while (i < size)
    {
        if (tmp->value < lowest)
            lowest = tmp->value;
        tmp = tmp->next;
        i++;
    }
    indices[j++] = lowest;

}

// simplify to work on the "indices" based off a position 
// in a sorted list; achieved with selection sort (kinda lol)
void    simplify_stack(t_stack **stack)
{
    int *indices;
    int size;

    size = get_stack_size(&stack);
    indices = (int *) malloc (size * sizeof(int));
    if (!indices)
        return ;
}