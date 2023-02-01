/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:46:59 by romachad          #+#    #+#             */
/*   Updated: 2023/01/28 01:21:58 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/libft.h"

void	fake_rotate_a(t_ps *ps)
{
	int	swap;
	int	i;

	if (ps->size_a > 1)
	{
		swap = ps->stack_a[0];
		i = -1;
		while (++i < ps->size_a - 1)
			ps->stack_a[i] = ps->stack_a[i + 1];
		ps->stack_a[i] = swap;
	}
	ps->count++;
}

void	fake_rotate_b(t_ps *ps)
{
	int	swap;
	int	i;

	if (ps->size_b > 1)
	{
		swap = ps->stack_b[0];
		i = -1;
		while (++i < ps->size_b - 1)
			ps->stack_b[i] = ps->stack_b[i + 1];
		ps->stack_b[i] = swap;
	}
	ps->count++;
}

void	fake_rotate_rr(t_ps *ps)
{
	int	swap;
	int	i;

	if (ps->size_a > 1)
	{
		swap = ps->stack_a[0];
		i = -1;
		while (++i < ps->size_a - 1)
			ps->stack_a[i] = ps->stack_a[i + 1];
		ps->stack_a[i] = swap;
	}
	if (ps->size_b > 1)
	{
		swap = ps->stack_b[0];
		i = -1;
		while (++i < ps->size_b - 1)
			ps->stack_b[i] = ps->stack_b[i + 1];
		ps->stack_b[i] = swap;
	}
	ps->count++;
}
