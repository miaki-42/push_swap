/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:07:48 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/10 14:36:43 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	t_node	*bottom;
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack->size <= 1)
		return ;
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
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack *stack)
{
	t_node	*bottom;
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack->size <= 1)
		return ;
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
	ft_putstr_fd("sb\n", 1);
}