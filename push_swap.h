/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:19:14 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/10 18:21:38 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	size_t	size;
}	t_stack;

// utils: libftに移動？
void	*free_ret_null(void *ptr);

// parse
t_stack	*args_to_lst(int argc, char *argv[]);

// stack
t_stack	*init_stack(void);
t_node	*create_node(int value);
void	append_node(t_stack *stack, t_node *new);
void	*free_stack_ret_null(t_stack *stack);

// operation
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	push_a(t_stack *stack_a, t_stack *stack_b);

void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);


#endif