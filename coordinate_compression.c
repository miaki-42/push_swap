/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:55:30 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/20 03:37:21 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*toarray(t_stack *stack_a)
{
	int		*arr;
	t_node	*now;
	size_t	i;

	if (stack_a->size == 0)
		return (free_stack_ret_null(stack_a));
	arr = malloc(sizeof(int) * stack_a->size);
	if (!arr)
		return (free_stack_ret_null(stack_a));
	now = stack_a->top;
	i = 0;
	while (i < stack_a->size)
	{
		arr[i] = now->value;
		now = now->next;
		i++;
	}
	return (arr);
}

static void	switch_value(int *n1, int *n2)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

static bool	bubble_sort(int *arr, t_stack *stack_a)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack_a->size - 1)
	{
		j = 0;
		while (j < stack_a->size - 1 - i)
		{
			if (arr[j] == arr[j + 1])
			{
				free(arr);
				free_stack_ret_null(stack_a);
				return (false);
			}
			else if (arr[j] > arr[j + 1])
				switch_value(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	return (true);
}

static int	binary_search(int *arr, int size, int n)
{
	int	left;
	int	right;
	int	index;

	left = 0;
	right = size - 1;
	while (true)
	{
		index = (left + right) / 2;
		if (n == arr[index])
			break ;
		else if (n < arr[index])
			right = index - 1;
		else
			left = index + 1;
	}
	return (index);
}

bool	compression(t_stack *stack_a)
{
	int		*arr;
	t_node	*now;
	size_t	i;

	arr = toarray(stack_a);
	if (!arr)
	{
		puterr();
		return (false);
	}
	if (!bubble_sort(arr, stack_a))
	{
		puterr();
		return (false);
	}
	now = stack_a->top;
	i = 0;
	while (i < stack_a->size)
	{
		now->value = binary_search(arr, stack_a->size, now->value);
		now = now->next;
		i++;
	}
	free(arr);
	return (true);
}
