/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:29:56 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/08 17:14:42 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Init stack & Create dummy-node
t_stack	*init_stack(void)
{
	t_stack	*stack;
	t_node	*dummy;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	dummy = create_node(0);
	if (!dummy)
		return (free_ret_null(stack));
	stack->top = dummy;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->prev = new;
	new->next = new;
	return (new);
}

void	append_node(t_stack *stack, t_node *new)
{
	t_node	*top;
	t_node	*bottom;

	top = stack->top;
	bottom = top->prev;
	bottom->next = new;
	new->prev = bottom;
	new->next = top;
	top->prev = new;
}

void	*free_stack_ret_null(t_stack *stack)
{
	t_node	*dummy;
	t_node	*tmp;
	size_t	i;

	dummy = stack->top;
	stack->top = dummy->next;
	i = 0;
	while (i < stack->size)
	{
		tmp = stack->top->next;
		free(stack->top);
		stack->top = tmp;
		i++;
	}
	free(dummy);
	free(stack);
	return (NULL);
}
