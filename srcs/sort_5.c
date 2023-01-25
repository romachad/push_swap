/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:22:58 by romachad          #+#    #+#             */
/*   Updated: 2023/01/25 04:14:24 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	choose_which_to_push(t_ps *ps)
{
	if (ps->stack_a[0] < ps->stack_a[1] \
			&& ps->stack_a[0] < ps->stack_a[ps->size_a - 1])
		push_b(ps);
	else if (ps->stack_a[1] < ps->stack_a[0] \
			&& ps->stack_a[1] < ps->stack_a[ps->size_a - 1])
	{
		swap_a(ps);
		push_b(ps);
	}
	else
	{
		rrotate_a(ps);
		push_b(ps);
	}
}

static void	sort_a_3(t_ps *ps)
{
	sort_3(ps, ps->stack_a, ps->size_a);
	if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
		return ;
	if (ps->stack_b[0] < ps->stack_b[1])
		swap_b(ps);
	push_a(ps);
	if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
		return ;
	if (ps->stack_a[0] > ps->stack_a[1])
		swap_a(ps);
	if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
		return ;
	push_a(ps);
	if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
		return ;
	if (ps->stack_a[0] > ps->stack_a[1])
		swap_a(ps);
	if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
		return ;
}

void	sort_5(t_ps *ps)
{
	while (is_sorted(ps->stack_a, ps->size_a) == 0 || ps->size_a != 5)
	{
		choose_which_to_push(ps);
		if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
			break ;
		if (ps->size_a == 3)
			sort_a_3(ps);
		if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
			break ;
	}
}
