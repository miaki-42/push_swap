/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:49:11 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/13 12:13:32 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *stack_a)
{
	if (stack_a->top == 0)
		return ;
	else
		swap(stack_a);
}

void	sort3(t_stack *stack_a)
{
	int	value1;
	int	value2;

	value1 = stack_a->top->value;
	value2 = stack_a->top->next->value;
	if (value1 == 0 && value2 == 1)
		return ;
	else if (value1 == 0 && value2 == 2)
	{
		reverse_rotate(stack_a);
	}
	else if (value1 == 1 && value2 == 0)
		swap(stack_a);
	else if (value1 == 1 && value2 == 2)
		reverse_rotate(stack_a);
	else if (value1 == 2 && value2 == 0)
		rotate(stack_a);
	else if (value1 == 2 && value2 == 1)
	{
		rotate(stack_a);
		swap(stack_a);
	}
}

void	sort4(t_stack *stack_a, t_stack *stack_b)
{
	int		value4;

	value4 = stack_a->top->prev->value;
	if (value4 == 0)
	{
		reverse_rotate(stack_a);
		if (is_sorted(stack_a))
			return ;
		push(stack_b, stack_a);
	}
	while (value4 != 0 && stack_a->size > 3)
	{
		if (is_sorted(stack_a))
			return ;
		if (stack_a->top->value == 0)
			push(stack_b, stack_a);
		else
			rotate(stack_a);
	}
	sort3(stack_a);
	push(stack_a, stack_b);
}

void	sort5(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
	{
		if (stack_a->size == 5 && is_sorted(stack_a))
			return ;
		if (stack_a->top->value == 0 || stack_a->top->value == 1)
			push(stack_b, stack_a);
		else
			rotate(stack_a);
	}
	if (stack_b->top->value == 0)
		swap(stack_b);
	sort3(stack_a);
	push(stack_a, stack_b);
	push(stack_a, stack_b);
}
