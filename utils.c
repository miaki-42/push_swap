/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:53:31 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/13 00:48:10 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_ret_null(void *ptr)
{
	free(ptr);
	return (NULL);
}

int		puterr(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

void	display_stack(t_stack *stack)
{
	t_node	*now;
	size_t	i;

	now = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (i + 1 != stack->size)
			ft_printf("%d ", now->value);
		else
			ft_printf("%d\n", now->value);
		now = now->next;
		i++;
	}
}
