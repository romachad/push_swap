/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_30pct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:59:26 by romachad          #+#    #+#             */
/*   Updated: 2023/01/27 22:10:12 by romachad         ###   ########.fr       */
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

void	fill_tmp(t_ps *ps)
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
#include "../headers/ft_printf.h"
#include <stdio.h>
/*static void	check_bfore_push(t_ps *ps)
{
	//if (ps->stack_b[0] > ps->stack_b[1] && ps->stack_b[0] > ps->stack_b[ps->size_b -1])
	if (ps->stack_b[0] < ps->stack_b[1] && ps->stack_b[0] < ps->stack_b[ps->size_b -1])
		return ;
	//else if (ps->stack_b[1] > ps->stack_b[0] && ps->stack_b[1] > ps->stack_b[ps->size_b -1])
	else if (ps->stack_b[1] < ps->stack_b[0] && ps->stack_b[1] < ps->stack_b[ps->size_b -1])
		swap_b(ps);
	//else if (ps->stack_b[ps->size_b -1] > ps->stack_b[0] && ps->stack_b[ps->size_b -1] > ps->stack_b[1])
	else if (ps->stack_b[ps->size_b -1] < ps->stack_b[0] && ps->stack_b[ps->size_b -1] < ps->stack_b[1])
		rrotate_b(ps);
}*/

static int	push_top(t_ps *ps, int i)
{
	double	pct;

	pct = 100.0 / ps->size_a;
	//printf("FUCKING FLOAT = %f\n", pct);
	if ((double)(ps->tmp[i] * pct) < 30.0)
	{
		//check_bfore_push(ps);
		push_b(ps);
		
	/*	if (ps->stack_b[0] == 2147446406 || ps->stack_b[0] == 2146946413 || ps->stack_b[0] == 2132121951 || ps->stack_b[0] == 2114951534 || ps->stack_b[0] == 2113877759)
		{
			ft_printf("----MERDA!!!\n");
			ft_printf("valor do i: %d\nsize_a = %d\n", i, ps->size_a);
			ft_printf("tmp[%d]: %d\n",i, ps->tmp[i]);
			printf("pct: %f\n", pct);
			ft_printf("----DUMP---\n");
			for (i = 0; i < ps->size_a; i++)
				ft_printf("pos a %d: %d\n",i ,ps->stack_a[i]);
			for (i = 0; i < ps->size_a; i++)
				ft_printf("sorted  %d: %d\n",i ,ps->sorted[i]);
			for (i = 0; i < ps->size_a; i++)
				ft_printf("tmp %d: %d\n",i ,ps->tmp[i]);
			for (i = 0; i < ps->size_b; i++)
				ft_printf("pos b %d: %d\n",i ,ps->stack_b[i]);
			ft_printf("----END DUMP---\n");
		}*/
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
			if (ps->stack_b[0] > ps->stack_b[ps->size_b -1])
				rotate_rr(ps);
			else
				rotate_a(ps);
			i++;
		}
	}
}
