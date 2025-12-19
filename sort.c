/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:01:00 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/20 03:33:33 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_sorted(t_stack *stack)
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

void	sort_under5(t_stack *stack_a, t_stack *stack_b)
{
	size_t	n;

	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			swap(stack_a);
		return ;
	}
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
	if (n == 5 && stack_b->top->value < stack_b->top->next->value)
		swap(stack_b);
	while (stack_b->size > 0)
		push(stack_a, stack_b);
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
