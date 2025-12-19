/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:49:11 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/20 04:31:57 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_just3(t_stack *stack)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = stack->top->value;
	val2 = stack->top->next->value;
	val3 = stack->top->prev->value;
	if (val1 < val2 && val2 < val3)
		return ;
	else if (val1 < val3 && val3 < val2)
	{
		reverse_rotate(stack);
		swap(stack);
	}
	else if (val2 < val1 && val1 < val3)
		swap(stack);
	else if (val2 < val3 && val3 < val1)
		rotate(stack);
	else if (val3 < val1 && val1 < val2)
		reverse_rotate(stack);
	else if (val3 < val2 && val2 < val1)
	{
		rotate(stack);
		swap(stack);
	}
}

static void	sort_just3_rev(t_stack *stack)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = stack->top->value;
	val2 = stack->top->next->value;
	val3 = stack->top->prev->value;
	if (val1 < val2 && val2 < val3)
	{
		rotate(stack);
		swap(stack);
	}
	else if (val1 < val3 && val3 < val2)
		rotate(stack);
	else if (val2 < val1 && val1 < val3)
		reverse_rotate(stack);
	else if (val2 < val3 && val3 < val1)
	{
		reverse_rotate(stack);
		swap(stack);
	}
	else if (val3 < val1 && val1 < val2)
		swap(stack);
	else if (val3 < val2 && val2 < val1)
		return ;
}

static void	sort_under3(t_stack *stack, bool rev)
{
	if (stack->size == 1)
		return ;
	else if (stack->size == 2)
	{
		if (rev && stack->top->value > stack->top->next->value)
			swap(stack);
		else if (!rev && stack->top->value < stack->top->next->value)
			swap(stack);
	}
	else
	{
		if (rev)
			sort_just3(stack);
		else
			sort_just3_rev(stack);
	}
}

void	sort_under6(t_stack *stack_a, t_stack *stack_b)
{
	size_t	n;

	if (stack_a->size <= 3)
		sort_under3(stack_a, true);
	else
	{
		n = stack_a->size;
		while (stack_a->size > 3)
		{
			if (stack_a->size == n && is_sorted(stack_a))
				return ;
			if (stack_a->top->value <= (int)n - 4)
				push(stack_b, stack_a);
			else
				rotate(stack_a);
		}
		sort_just3(stack_a);
		sort_under3(stack_b, false);
		while (stack_b->size > 0)
			push(stack_a, stack_b);
	}
}
