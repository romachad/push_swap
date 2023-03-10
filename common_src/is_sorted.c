/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:28:58 by romachad          #+#    #+#             */
/*   Updated: 2023/01/25 03:35:25 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_sorted(int *stack, int size)
{
	int	i;

	i = -1;
	while (++i < (size - 1))
	{
		if (stack[i] > stack[i + 1])
			return (0);
	}
	return (1);
}
