/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:12:20 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/19 17:12:01 by komatsuk         ###   ########.fr       */
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
	}

	// テスト
	display_stack(stack_a);
	sort_under6(stack_a, stack_b);
	display_stack(stack_a);

	return (0);
}

