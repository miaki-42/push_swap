/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:33:16 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/07 03:38:50 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_arg(int argc, char *argv)
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
		i++;
	}
	return (args_joined);
}

static char	**split_token(int argc, char *argv[])
{
	char	*args_joined;
	char	**tokens;

	args_joined = join_arg(argc, argv);
	if (!args_joined)
		return (NULL);
	tokens = ft_split(args_joined, ' ');
	if (!tokens)
		return (free_ret_null(args_joined));
	free(args_joined);
	return (tokens);
}

t_stack	*args_to_lst(int argc, char *argv[])
{
	t_stack	*stack;
	char	**tokens;
	size_t	i;

	tokens = split_token(argc, argv);
	if (!tokens)
		return (NULL);
	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 0;
	while (tokens[i])
	{
		if (stack->size == 0)
		{

		}
		else
		{
			
		}
		i++;
	}
}