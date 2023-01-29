/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_30pct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:59:26 by romachad          #+#    #+#             */
/*   Updated: 2023/01/28 22:52:46 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	fill_sorted(t_ps *ps)
{
	char	flag;
	int		i;
	int		swap;

	i = -1;
	while (++i < ps->size_a)
		ps->sorted[i] = ps->stack_a[i];
	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		i = -1;
		while (++i < (ps->size_a - 1))
		{
			if (ps->sorted[i] > ps->sorted[i + 1])
			{
				swap = ps->sorted[i];
				ps->sorted[i] = ps->sorted[i + 1];
				ps->sorted[i + 1] = swap;
				flag = 0;
			}
		}
	}
}

static void	fill_tmp(t_ps *ps)
{
	int	i;
	int	count;

	count = -1;
	while (++count < ps->size_a)
	{
		i = -1;
		while (++i < ps->size_a)
		{
			if (ps->sorted[count] == ps->stack_a[i])
			{
				ps->tmp[i] = count + 1;
				break ;
			}
		}
	}
}

static int	push_top(t_ps *ps, int i)
{
	double	pct;

	pct = 100.0 / ps->size_a;
	if ((double)(ps->tmp[i] * pct) < 30.0)
	{
		push_b(ps);
		return (1);
	}
	return (0);
}

void	push_30pct(t_ps *ps)
{
	int	i;

	while (ps->size_a > 5)
	{
		i = 0;
		fill_sorted(ps);
		fill_tmp(ps);
		while (push_top(ps, i) == 0)
		{
			if (ps->size_b > 1 && ps->stack_b[0] > ps->stack_b[ps->size_b -1])
				rotate_rr(ps);
			else
				rotate_a(ps);
			i++;
		}
	}
}
