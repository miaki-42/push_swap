/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:05:45 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/10 12:07:00 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	stack->top = stack->top->next;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack *stack)
{
	stack->top = stack->top->next;
	ft_putstr_fd("rb\n", 1);
}

void	reverse_rotate_a(t_stack *stack)
{
	stack->top = stack->top->prev;
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stack *stack)
{
	stack->top = stack->top->prev;
	ft_putstr_fd("rrb\n", 1);
}