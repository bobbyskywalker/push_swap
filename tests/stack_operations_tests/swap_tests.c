#include "../../includes/push_swap.h"

void init_stack(t_stack **stack_a, t_stack **stack_b)
{
    lstadd_front(stack_a, create_node(89));
    lstadd_front(stack_a, create_node(12));
    lstadd_front(stack_a, create_node(1));
    lstadd_front(stack_a, create_node(21));

    lstadd_front(stack_b, create_node(3));
    lstadd_front(stack_b, create_node(4));
    lstadd_front(stack_b, create_node(5));
    lstadd_front(stack_b, create_node(6));

    t_stack *temp = *stack_a;
    t_stack *temp_b = *stack_b;
    printf("stack_a: \n");
    for (int i = 0; temp; i++)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }

    printf("\nstack_b: \n");
    for (int i = 0; temp_b; i++)
    {
        printf("%d\n", temp_b->value);
        temp_b = temp_b->next;
    }
}
// cc tests/stack_operations_tests/swap_tests.c src/list_operations/sll_lib.c src/stack_operations/swap.c lib/libft/libft.a -g
int main()
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    printf("init: \n");
    init_stack(&stack_a, &stack_b);

    printf("\nsecond: \n");
    swap_s(&stack_a, &stack_b);

    t_stack *temp = stack_a;
    printf("stack_a: \n");
    for (int i = 0; temp; i++)
    {
        printf("\n%d", temp->value);
        temp = temp->next;
    }
    t_stack *temp2 = stack_b;
    printf("\n\nstack_b: \n");
    for(int i = 0; temp2; i++)
    {
        printf("\n%d", temp2->value);
        temp2 = temp2->next;
    }
    return 0;
}
