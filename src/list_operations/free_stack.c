#include "../../includes/push_swap.h"

// line 13 cnd breaks the circular reference (hangs in inf loop otherwise)
void free_stack(t_stack **head)
{
    t_stack *tmp;
    t_stack *current;

    if (!head || !*head)
        return;
    
    current = *head;
    (*head)->prev->next = NULL;
    
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    *head = NULL;
}


