/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:48:43 by romachad          #+#    #+#             */
/*   Updated: 2023/01/25 02:47:00 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/libft.h"

static void	shift_down(int *stack, int *size)
{
	int	i;

	i = *size;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	*size += 1;
}

static void	shift_up(int *stack, int *size)
{
	int	i;

	i = 0;
	while (i < (*size - 1))
	{
		stack[i] = stack[i + 1];
		i++;
	}
	*size -= 1;
}

void	push_a(t_ps *ps)
{
	if (ps->size_b > 0)
	{
		shift_down(ps->stack_a, &ps->size_a);
		ps->stack_a[0] = ps->stack_b[0];
		shift_up(ps->stack_b, &ps->size_b);
	}
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_ps *ps)
{
	if (ps->size_a > 0)
	{
		shift_down(ps->stack_b, &ps->size_b);
		ps->stack_b[0] = ps->stack_a[0];
		shift_up(ps->stack_a, &ps->size_a);
	}
	ft_putstr_fd("pb\n", 1);
}
