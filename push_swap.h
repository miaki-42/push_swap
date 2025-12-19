/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:19:14 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/19 17:21:25 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// stack-nbr
typedef struct s_stack
{
	t_node	*top;
	size_t	size;
	int		nbr;
}	t_stack;


// parse
t_stack	*args_to_lst(int argc, char *argv[]);

// stack
t_stack	*init_stack(int nbr);
t_stack	*create_stack_b(t_stack *stack_a);
t_node	*create_node(int value);
void	append_node(t_stack *stack, t_node *new);
void	*free_stack_ret_null(t_stack *stack);

// coordinate_compression
bool	compression(t_stack *stack_a);

// operation
void	swap(t_stack *stack);
void	push(t_stack *stack1, t_stack *stack2);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

// operation_sup
t_node	*pop(t_stack *stack);
void	prepend(t_stack *stack, t_node *node);

// sort_small
void	sort_under6(t_stack *stack_a, t_stack *stack_b);

// sort
bool	is_sorted(t_stack *stack);

// utils
void	*free_ret_null(void *ptr);
int		puterr(void);
void	display_stack(t_stack *stack);

#endif