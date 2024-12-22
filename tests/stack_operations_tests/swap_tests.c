#include "../../includes/push_swap.h"

void init_stack(t_stack **stack_a)
{
    lstadd_front(stack_a, create_node(89));
    lstadd_front(stack_a, create_node(12));
    lstadd_front(stack_a, create_node(1));
    lstadd_front(stack_a, create_node(21));

    t_stack *temp = *stack_a;
    for (int i = 0; temp; i++)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}
// cc tests/stack_operations_tests/swap_tests.c src/list_operations/sll_lib.c src/stack_operations/swap.c lib/libft/libft.a -g
int main()
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    printf("init: \n");
    init_stack(&stack_a);

    printf("\nsecond: \n");
    swap_ab(&stack_a);

    t_stack *temp = stack_a;
    for (int i = 0; temp; i++)
    {
        printf("\n%d", temp->value);
        temp = temp->next;
    }
    return 0;
}
