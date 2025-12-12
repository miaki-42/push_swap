/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:12:20 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/13 02:25:43 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b;

	if (argc > 1)
	{
		// 入力
		stack_a = args_to_lst(argc, argv);
		if (!stack_a)
			return (puterr());


		// 座標圧縮 (構造体.sizeでmalloc、バブルソート、値の付け替え二部探索)
	
		// ソート
	}

	// てすてす
	t_node	*now;
	now = stack_a->top;
	for (size_t i=0; i < stack_a->size; i++)
	{
		ft_putnbr_fd(now->value, 1);
		now = now->next;
	}
	ft_putchar_fd('\n', 1);
	stack_b = args_to_lst(argc, argv);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	now = stack_a->top;
	for (size_t i=0; i < stack_a->size; i++)
	{
		ft_putnbr_fd(now->value, 1);
		now = now->next;
	}

	return (0);
}

