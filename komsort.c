/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   komsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:49:00 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/21 18:22:05 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_min(t_stack *stack_b, size_t rot, size_t rev, int target)
{
	if (rot < rev)
	{
		while (stack_b->top->value != target)
			rotate(stack_b);
	}
	else
	{
		while (stack_b->top->value != target)
			reverse_rotate(stack_b);
	}
}

static void	rotate_for_insert(t_stack *stack_b, int target)
{
	t_node	*tmp;
	size_t	rot;
	size_t	rev;

	rot = 0;
	tmp = stack_b->top;
	while (tmp->value != target)
	{
		tmp = tmp->next;
		rot++;
	}
	rev = 0;
	tmp = stack_b->top;
	while (tmp->value != target)
	{
		tmp = tmp->prev;
		rev++;
	}
	rotate_min(stack_b, rot, rev, target);
}

static void	for_insert(t_stack *stack_b, int val)
{
	int		target;
	int		max;
	t_node	*tmp;
	size_t	i;

	target = -1;
	max = -1;
	tmp = stack_b->top;
	i = 0;
	while (i < stack_b->size)
	{
		if (tmp->prev->value > val && val > tmp->value)
		{
			target = tmp->value;
			break ;
		}
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
		i++;
	}
	if (target == -1)
		target = max;
	rotate_for_insert(stack_b, target);
}

void	komsort(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	cnt;

	chunk_size = stack_a->size / 6;
	cnt = 0;
	while (stack_a->size)
	{
		if (stack_a->top->value < chunk_size * (cnt / chunk_size + 1))
		{
			if (cnt < 2)
				push(stack_b, stack_a);
			else
			{
				for_insert(stack_b, stack_a->top->value);
				push(stack_b, stack_a);
			}
			cnt++;
		}
		else
			rotate(stack_a);
	}
	for_insert(stack_b, -1);
	while (stack_b->size)
		push(stack_a, stack_b);
}
