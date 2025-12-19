/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:12:20 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/13 12:14:33 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		stack_a = args_to_lst(argc, argv);
		if (!stack_a)
			return (puterr());
		stack_b = init_stack(1);
		if (!stack_b)
		{
			free_stack_ret_null(stack_a);
			return (puterr());
		}
		// 座標圧縮 (構造体.sizeでmalloc、バブルソート、値の付け替え二部探索、同値のエラーチェック)

		// ソート
		// sort();
	}

	// テスト
	display_stack(stack_a);
	sort_under6(stack_a, stack_b);
	display_stack(stack_a);

	return (0);
}

