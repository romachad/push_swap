/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:05:01 by romachad          #+#    #+#             */
/*   Updated: 2023/01/21 15:10:16 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rev_sort_3(t_ps *ps, int *stack, int size)
{
	if (size == 3)
	{
		if (stack[0] < stack[1] && stack[1] < stack[2])
		{
			swap_b(ps);
			rrotate_b(ps);
		}
		else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] < stack[2])
			rotate_b(ps);
		else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] > stack[2])
		{
			rotate_b(ps);
			swap_b(ps);
			rrotate_b(ps);
		}
		else if (stack[0] < stack[1] && stack[1] > stack[2])
			swap_b(ps);
		else if (stack[0] > stack[1] && stack[1] < stack[2])
			rrotate_b(ps);
	}
}

void	sort_3(t_ps *ps, int *stack, int size)
{
	if (size == 3)
	{
		if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] < stack[2])
		{
			rrotate_a(ps);
			swap_a(ps);
		}
		else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] > stack[2])
			rotate_a(ps);
		else if (stack[0] > stack[1] && stack[1] > stack[2])
		{
			swap_a(ps);
			rrotate_a(ps);
		}
		else if (stack[0] < stack[1] && stack[1] > stack[2])
			rrotate_a(ps);
		else if (stack[0] > stack[1] && stack[1] < stack[2])
			swap_a(ps);
	}
}
