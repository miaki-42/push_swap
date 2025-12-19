/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:12:20 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/20 04:34:34 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = args_to_lst(argc, argv);
	if (!stack_a)
		return (1);
	if (stack_a->size != 0)
	{
		if (!compression(stack_a))
			return (1);
		stack_b = create_stack_b(stack_a);
		if (!stack_b)
			return (1);
		if (stack_a->size <= 6)
			sort_under6(stack_a, stack_b);
		else
			radix_sort(stack_a, stack_b);
		free_stack_ret_null(stack_a);
		free_stack_ret_null(stack_b);
	}
	return (0);
}

// 要確認: stack->size == 0