/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:07:48 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/13 02:21:48 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*bottom;
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack->size >= 2)
	{
		bottom = stack->top->prev;
		first = stack->top;
		second = first->next;
		third = second->next;
		bottom->next = second;
		second->prev = bottom;
		second->next = first;
		first->prev = second;
		first->next = third;
		third->prev = first;
		stack->top = second;
		if (stack->nbr == 0)
			ft_putstr_fd("sa\n", 1);
		else
			ft_putstr_fd("sb\n", 1);
	}
}

void	push(t_stack *stack1, t_stack *stack2)
{
	t_node	*node;

	if (stack2->size >= 1)
	{
		node = pop(stack2);
		prepend(stack1, node);
		if (stack1->nbr == 0)
			ft_putstr_fd("pa\n", 1);
		else
			ft_putstr_fd("pb\n", 1);
	}
}

void	rotate(t_stack *stack)
{
	if (stack->size >= 2)
	{
		stack->top = stack->top->next;
		if (stack->nbr == 0)
			ft_putstr_fd("ra\n", 1);
		else
			ft_putstr_fd("rb\n", 1);	
	}
}

void	reverse_rotate(t_stack *stack)
{
	if (stack->size >= 2)
	{
		stack->top = stack->top->prev;
		if (stack->nbr == 0)
			ft_putstr_fd("rra\n", 1);
		else
			ft_putstr_fd("rrb\n", 1);
	}
}
