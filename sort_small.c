/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:49:11 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/13 02:33:31 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort2(t_stack *stack_a)
{
	if (stack_a->top == 0)
		return ;
	else
		swap(stack_a);
}

void	sort3(t_stack *stack_a)
{
	int	value1;
	int	value2;

	value1 = stack_a->top->value;
	value2 = stack_a->top->next->value;
	if (value1 == 0 && value2 == 1)
		return ;
	else if (value1 == 0 && value == 2)
	{
		reverse_rotate(stack_a);
	}
	else if (value1 == 1 && value2 == 0)
		swap(stack_a);
	else if (value1 == 1 && value2 == 2)
		reverse_rotate(stack_a);
	else if (value1 == 2 && value2 == 0)
		rotate(stack_a);
	else if (value1 == 2 && value2 == 1)
	{
		rotate(stack_a);
		swap(stack_a);
	}
}

void	sort4(t_stack *stack_a, t_stack *stack_b)
{
	
}

void	sort5(t_stack *stack_a, t_stack *stack_b)
{
	
}