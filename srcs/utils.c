/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:50:46 by romachad          #+#    #+#             */
/*   Updated: 2023/01/22 21:58:58 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	put_smallest_top(t_ps *ps)
{
	int	n;
	int	i;

	n = ps->stack_a[0];
	i = -1;
	while (++i < ps->size_a)
	{
		if (n > ps->stack_a[i])
			n = ps->stack_a[i];
	}
	i = -1;
	while (ps->stack_a[++i] != n)
		;
	if (i <= (ps->size_a / 2))
	{
		while (ps->stack_a[0] != n)
			rotate_a(ps);
	}
	else
	{
		while (ps->stack_a[0] != n)
			rrotate_a(ps);
	}
}
