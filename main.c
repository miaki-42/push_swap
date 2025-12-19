/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:12:20 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/19 17:25:00 by komatsuk         ###   ########.fr       */
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
		if (!compression(stack_a))
			return (puterr());
	
		// ソート
		stack_b = create_stack_b(stack_a);
		if (!stack_b)
			return (puterr());
		// sort(stack_a, stack_b);
	}

	// テスト
	display_stack(stack_a);
	free_stack_ret_null(stack_a);
	free_stack_ret_null(stack_b);

	return (0);
}

