/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:01:00 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/21 12:49:12 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*now;
	int		prev;
	size_t	i;

	now = stack->top;
	prev = -1;
	i = 0;
	while (i < stack->size)
	{
		if (now->value < prev)
			return (false);
		prev = now->value;
		now = now->next;
		i++;
	}
	return (true);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		bit;
	size_t	n;

	bit = 0;
	while (!is_sorted(stack_a))
	{
		n = stack_a->size;
		while (n > 0)
		{
			if ((stack_a->top->value & (1 << bit)) == 0)
				push(stack_b, stack_a);
			else
				rotate(stack_a);
			n--;
		}
		while (stack_b->size)
			push(stack_a, stack_b);
		bit++;
	}
}
