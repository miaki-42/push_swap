/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:33:16 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/21 18:39:58 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_args(int argc, char **argv)
{
	char	*args_joined;
	char	*tmp;
	char	*delim;
	int		i;

	delim = " ";
	args_joined = ft_calloc(1, sizeof(char));
	if (!args_joined)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		tmp = args_joined;
		args_joined = ft_strjoin(args_joined, argv[i]);
		if (!args_joined)
			return (free_ret_null(tmp));
		free(tmp);
		tmp = args_joined;
		args_joined = ft_strjoin(args_joined, delim);
		if (!args_joined)
			return (free_ret_null(tmp));
		free(tmp);
		i++;
	}
	return (args_joined);
}

static char	**split_tokens(int argc, char *argv[])
{
	char	*args_joined;
	char	**tokens;

	args_joined = join_args(argc, argv);
	if (!args_joined)
		return (NULL);
	tokens = ft_split(args_joined, ' ');
	if (!tokens)
		return (free_ret_null(args_joined));
	free(args_joined);
	return (tokens);
}

static void	free_tokens(char **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static t_stack	*tokens_to_lst(t_stack *stack_a, char **tokens)
{
	t_node	*new;
	int		value;

	while (tokens[stack_a->size])
	{
		if (!my_mimic_atoi(tokens[stack_a->size], &value))
		{
			free_tokens(tokens);
			return (free_stack_ret_null(stack_a));
		}
		new = create_node(value);
		if (!new)
		{
			free_tokens(tokens);
			return (free_stack_ret_null(stack_a));
		}
		append_node(stack_a, new);
		stack_a->size++;
	}
	free_tokens(tokens);
	return (stack_a);
}

t_stack	*args_to_lst(int argc, char *argv[])
{
	char	**tokens;
	t_stack	*stack_a;

	tokens = split_tokens(argc, argv);
	if (!tokens)
	{
		puterr();
		return (NULL);
	}
	stack_a = init_stack(0);
	if (!stack_a)
	{
		free_tokens(tokens);
		puterr();
		return (NULL);
	}
	if (!(tokens_to_lst(stack_a, tokens)))
	{
		puterr();
		return (NULL);
	}
	return (stack_a);
}
