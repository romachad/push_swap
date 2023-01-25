/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:22:59 by romachad          #+#    #+#             */
/*   Updated: 2023/01/25 03:50:50 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/libft.h"

void	rrotate_a(t_ps *ps)
{
	int	swap;
	int	i;

	if (ps->size_a > 1)
	{
		swap = ps->stack_a[ps->size_a - 1];
		i = ps->size_a;
		while (--i > 0)
			ps->stack_a[i] = ps->stack_a[i - 1];
		ps->stack_a[0] = swap;
	}
	ft_putstr_fd("rra\n", 1);
}

void	rrotate_b(t_ps *ps)
{
	int	swap;
	int	i;

	if (ps->size_b > 1)
	{
		swap = ps->stack_b[ps->size_b - 1];
		i = ps->size_b;
		while (--i > 0)
			ps->stack_b[i] = ps->stack_b[i - 1];
		ps->stack_b[0] = swap;
	}
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_ps *ps)
{
	int	swap;
	int	i;

	if (ps->size_a > 1)
	{
		swap = ps->stack_a[ps->size_a - 1];
		i = ps->size_a;
		while (--i > 0)
			ps->stack_a[i] = ps->stack_a[i - 1];
		ps->stack_a[0] = swap;
	}
	if (ps->size_b > 1)
	{
		swap = ps->stack_b[ps->size_b - 1];
		i = ps->size_b;
		while (--i > 0)
			ps->stack_b[i] = ps->stack_b[i - 1];
		ps->stack_b[0] = swap;
	}
	ft_putstr_fd("rrr\n", 1);
}
