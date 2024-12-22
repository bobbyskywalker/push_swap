# include "../../includes/push_swap.h"

t_stack	*create_node(int content)
{
	t_stack	*head;

	head = (t_stack *) malloc (sizeof(t_stack));
	if (!head)
		return (NULL);
	head->value = content;
	head->next = NULL;
	head->prev = NULL;
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
	t_stack	*last;

	if (!new)
		return;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return;
	}
	last = (*stack)->prev;
	new->next = *stack;
	new->prev = last;
	(*stack)->prev = new;
	last->next = new;
	*stack = new;
}

void	lstadd_end(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return;
	}
	last = (*stack)->prev;
	new->next = *stack;
	new->prev = last;
	last->next = new;
	(*stack)->prev = new;
}

// first 'if'- one node in stack, second 'if'- when removing head
void	rm_node(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return;
	if (*stack == node && node->next == node)
	{
    	free(node);
    	*stack = NULL;
    	return;
	}

	if (*stack == node)
		*stack = node->next;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}
