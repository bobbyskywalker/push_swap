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

    printf("stack_a:\n");
    t_stack *temp = *stack_a;
    if (temp)
    {
        do {
            printf("%d\n", temp->value);
            temp = temp->next;
        } while (temp != *stack_a);
    }

    printf("\nstack_b:\n");
    t_stack *temp_b = *stack_b;
    if (temp_b)
    {
        do {
            printf("%d\n", temp_b->value);
            temp_b = temp_b->next;
        } while (temp_b != *stack_b);
    }
}

// cc tests/stack_operations_tests/push_tests.c src/list_operations/dll_lib.c src/stack_operations/push.c lib/libft/libft.a -g
int main()
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    printf("init:\n");
    init_stack(&stack_a, &stack_b);

    printf("\nAfter push:\n");
    push(&stack_a, &stack_b);

    printf("stack_a:\n");
    t_stack *temp = stack_a;
    if (temp)
    {
        do {
            printf("%d\n", temp->value);
            temp = temp->next;
        } while (temp != stack_a);
    }

    printf("\nstack_b:\n");
    t_stack *temp2 = stack_b;
    if (temp2)
    {
        do {
            printf("%d\n", temp2->value);
            temp2 = temp2->next;
        } while (temp2 != stack_b);
    }

    return 0;
}
