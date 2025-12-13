/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:29:56 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/13 12:11:54 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int nbr)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	stack->nbr = nbr;
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

	if (stack->size == 0)
		stack->top = new;
	else
	{
		top = stack->top;
		bottom = top->prev;
		bottom->next = new;
		new->prev = bottom;
		new->next = top;
		top->prev = new;
	}
}

void	*free_stack_ret_null(t_stack *stack)
{
	t_node	*tmp;
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		tmp = stack->top->next;
		free(stack->top);
		stack->top = tmp;
		i++;
	}
	free(stack);
	return (NULL);
}

bool	is_sorted(t_stack *stack)
{
	int		prev;
	size_t	i;

	prev = -1;
	i = 0;
	while (i < stack->size)
	{
		if (stack->top->value < prev)
			return (false);
		prev = stack->top->value;
		stack->top = stack->top->next;
		i++;
	}
	return (true);
}
