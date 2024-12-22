# include "../../includes/push_swap.h"

t_stack	*create_node(int content)
{
	t_stack	*head;

	head = (t_stack *) malloc (sizeof(t_stack));
	if (!head)
		return (NULL);
	head->value = content;
	head->next = NULL;
	return (head);
}

t_stack	*get_last(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

void	lstadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	lstadd_end(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = get_last(*stack);
	if (!last)
		*stack = new;
	else
		last->next = new;
}

void *rm_node(t_stack **stack, t_stack *node)
{
    t_stack	*tmp;

    tmp = *stack;
    if (!tmp)
        return (NULL);
    if (tmp == node)
    {
        *stack = (*stack)->next;
        free(node);
        return (NULL);
    }
    while (tmp->next && tmp->next != node)
        tmp = tmp->next;
    if (tmp->next == node)
    {
        tmp->next = node->next;
        free(node);
        return (NULL);
    }
}