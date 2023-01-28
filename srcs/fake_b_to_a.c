/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:47:45 by romachad          #+#    #+#             */
/*   Updated: 2023/01/28 15:35:16 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
//#include "../headers/ft_printf.h"
static int	fake_is_the_smallest(int *stack, int size, int n)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (stack[i] < n)
			return (0);
	}
	return (1);
}

static void	fake_put_smallest_after_n(t_ps *ps, int n)
{
	int	i;
	int	after_n;

	fill_sorted(ps);
	i = -1;
	while (n > ps->sorted[++i] && i < ps->size_a);
		;
	after_n = ps->sorted[i];
	i = -1;
	while (ps->stack_a[++i] != after_n)
		;
	if (i <= (ps->size_a / 2))
	{
		while (ps->stack_a[0] != after_n)
		{
			fake_rotate_a(ps);
		}
	}
	else
	{
		while (ps->stack_a[0] != after_n)
		{
			fake_rrotate_a(ps);
		}
	}
}

static void	fake_evaluate(t_ps *ps)
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
	if (fake_is_the_smallest(ps->stack_a, ps->size_a, ps->stack_b[0]) \
			&& is_sorted(ps->sorted, ps->size_a + 1))
		fake_push_a(ps);
	else if (fake_is_the_smallest(ps->stack_a, ps->size_a, ps->stack_b[0]))
	{
		fake_put_smallest_top(ps);
		fake_push_a(ps);
	}
	else
	{
		fake_put_smallest_after_n(ps, ps->stack_b[0]);
		fake_push_a(ps);
		if (ps->stack_a[0] > ps->stack_a[1])
			fake_swap_a(ps);
	}
}

static void	fake_push_smallest(t_ps *ps, int int_comp)
{
	int	*s;
	int	i;
	int	n;

	i = -1;
	s = ps->stack_b;
	n = s[0];
	while (++i < int_comp && i < ps->size_b)
		if (n > s[i])
			n = s[i];
	i = 0;
	while(--i > -int_comp && ps->size_b + i > 0)
		if (n > s[ps->size_b + i])
			n = s[ps->size_b +i];
	i = -1;
	while (++i < int_comp && i < ps->size_b)
		if (s[i] == n)
			break ;
	if (s[i] == n)
		while (s[0] != n)
			fake_rotate_b(ps);
	else
		while (s[0] != n)
			fake_rrotate_b(ps);
	fake_evaluate(ps);
}

void	fake_b_to_a(t_ps *ps, int int_comp)
{
	while (ps->size_b > 0)
	{
		fake_push_smallest(ps, int_comp);
	}
}
