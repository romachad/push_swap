/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:15:39 by romachad          #+#    #+#             */
/*   Updated: 2023/01/18 21:14:35 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/libft.h"

void	swap_a(t_ps *ps)
{
	int	swap;

	if (ps->size_a > 1)
	{
		swap = ps->stack_a[1];
		ps->stack_a[1] = ps->stack_a[0];
		ps->stack_a[0] = swap;
	}
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_ps *ps)
{
	int	swap;

	if (ps->size_b > 1)
	{
		swap = ps->stack_b[1];
		ps->stack_b[1] = ps->stack_b[0];
		ps->stack_b[0] = swap;
	}
	ft_putstr_fd("sb\n", 1);
}

void	swap_ss(t_ps *ps)
{
	int	swap;

	if (ps->size_a > 1)
	{
		swap = ps->stack_a[1];
		ps->stack_a[1] = ps->stack_a[0];
		ps->stack_a[0] = swap;
	}
	if (ps->size_b > 1)
	{
		swap = ps->stack_b[1];
		ps->stack_b[1] = ps->stack_b[0];
		ps->stack_b[0] = swap;
	}
	ft_putstr_fd("ss\n", 1);
}
