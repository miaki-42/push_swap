/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:53:24 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/13 02:05:55 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop(t_stack *stack)
{
	t_node	*node;
	t_node	*top;

	node = stack->top;
	if (stack->size == 1)
		stack->top = NULL;
	else if (stack->size >= 2)
	{
		top = stack->top;
		top->prev->next = top->next;
		top->next->prev = top->prev;
		stack->top = top->next;
	}
	stack->size--;
	return (node);
}

void	prepend(t_stack *stack, t_node *node)
{
	t_node	*top;

	if (stack->size == 0)
	{
		node->prev = node;
		node->next = node;
	}
	else
	{
		top = stack->top;
		top->prev->next = node;
		node->prev = top->prev;
		node->next = top;
		top->prev = node;
	}
	stack->top = node;
	stack->size++;
}
