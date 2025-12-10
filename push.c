/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:53:24 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/10 18:18:13 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top_a;
	t_node	*top_b;

	if (stack_b->size == 0)
		return ;
	top_b = stack_b->top;
	top_b->prev->next = top_b->next;
	top_b->next->prev = top_b->prev;
	stack_b->top = top_b->next;
	stack_b->size--;
	top_a = stack_a->top;
	top_a->prev->next = top_b;
	top_b->prev = top_a->prev;
	top_b->next = top_a;
	top_a->prev = top_b;
	stack_a->top = top_b;
	stack_a->size++;
}

