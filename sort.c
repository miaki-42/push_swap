/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:01:00 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/19 17:21:34 by komatsuk         ###   ########.fr       */
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
