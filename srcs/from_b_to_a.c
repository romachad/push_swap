/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:47:45 by romachad          #+#    #+#             */
/*   Updated: 2023/01/22 21:56:23 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	is_the_smallest(int *stack, int size, int n)
{
	int	i;

	i = - 1;
	while (++i < size)
	{
		if (stack[i] < n)
			return (0);
	}
	return (1);
}

static void	put_smallest_after_n(t_ps *ps, int n)
{
	int	i;
	int	after_n;

	fill_sorted(ps);
	i = -1;
	while (n > ps->sorted[++i])
		;
	after_n = ps->sorted[i];
	i = -1;
	while (ps->stack_a[++i] != after_n)
		;
	if (i <= (ps->size_a / 2))
	{
		while (ps->stack_a[0] != after_n)
			rotate_a(ps);
	}
	else
	{
		while (ps->stack_a[0] != after_n)
			rrotate_a(ps);
	}
}

static void	evaluate(t_ps *ps)
{
	int	i;

	fill_sorted(ps);
	if (ps->size_a < ps->full_size)
	{
		i = ps->size_a + 1;
		while (--i > 0)
			ps->sorted[i] = ps->stack_a[i - 1];
		ps->sorted[0] = ps->stack_b[0];
	}
	if (is_the_smallest(ps->stack_a, ps->size_a, ps->stack_b[0]) && is_sorted(ps->sorted, ps->size_a + 1))
		push_a(ps);
	else if (is_the_smallest(ps->stack_a, ps->size_a, ps->stack_b[0]))
	{
		put_smallest_top(ps);
		push_a(ps);
	}
	else
	{
		put_smallest_after_n(ps, ps->stack_b[0]);
		push_a(ps);
	}
}

void	from_b_to_a(t_ps *ps)
{
	while (ps->size_b > 0)
	{
		if (ps->stack_b[0] > ps->stack_b[1] && ps->stack_b[0] > ps->stack_b[ps->size_b - 1])
			evaluate(ps);
		else if (ps->stack_b[1] > ps->stack_b[0] && ps->stack_b[1] > ps->stack_b[ps->size_b - 1])
		{
			rotate_b(ps);
			evaluate(ps);
		}
		else
		{
			rrotate_b(ps);
			evaluate(ps);
		}
	}
}
