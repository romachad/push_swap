/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:02:42 by romachad          #+#    #+#             */
/*   Updated: 2023/01/21 20:57:38 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	smallest(int *stack, int size, int n)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (n > stack[i])
			return (0);
	}
	return (1);
}

int	biggest(int *stack, int size, int n)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (n < stack[i])
			return (0);
	}
	return (1);
}
#include "../headers/libft.h"
#include "../headers/ft_printf.h"
void	mid_a(t_ps *ps)
{
	if (smallest(ps->stack_a, ps->size_a, ps->stack_a[0]) && biggest(ps->stack_b, ps->size_b, ps->stack_a[0]))
	{
	//	ft_putstr_fd("ENTRAMO NO MID! CARAIO\n", 1);
		swap_a(ps);
		rotate_a(ps);
		swap_a(ps);
		rotate_a(ps);
		swap_a(ps);
		rrotate_a(ps);
		rrotate_a(ps);

	//	int i;
	//	ft_putstr_fd("---------------\n", 1);
	//	for (i = 0; i < ps->size_a; i++)
	//		ft_printf("pos a %i: %i\n", i, ps->stack_a[i]);
	//	for (i = 0; i < ps->size_b; i++)
	//		ft_printf("pos b %i: %i\n", i, ps->stack_b[i]);
	//	ft_putstr_fd("---------------\n", 1);
	}
}
