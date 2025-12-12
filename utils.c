/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 02:53:31 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/13 00:48:10 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_ret_null(void *ptr)
{
	free(ptr);
	return (NULL);
}

int		puterr(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}