/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:22:58 by romachad          #+#    #+#             */
/*   Updated: 2023/01/22 14:24:21 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

#include "../headers/ft_printf.h"
//void	sort_5(t_ps *ps, int *stack, int size)
void	sort_5(t_ps *ps)
{
	int	count_push;

	/*int i;
	ft_printf("----VAI COMECAR A PUTARIA!\n");
	for (i = 0; i < ps->size_a; i++)
		ft_printf("pos a %i: %i\n", i, ps->stack_a[i]);
	for (i = 0; i < ps->size_a; i++)
		ft_printf("pos b %i: %i\n", i, ps->stack_b[i]);*/

	count_push = 0;
	while (is_sorted(ps->stack_a, ps->size_a) == 0 || ps->size_a != 5)
	{
		if (ps->stack_a[0] < ps->stack_a[1] && ps->stack_a[0] < ps->stack_a[ps->size_a - 1])
		{
			push_b(ps);
			count_push++;
		}
		else if (ps->stack_a[1] < ps->stack_a[0] && ps->stack_a[1] < ps->stack_a[ps->size_a - 1])
		{
			swap_a(ps);
			push_b(ps);
			count_push++;
		}
		else
		{
			rrotate_a(ps);
			push_b(ps);
		}
		if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
			break ;
		if (ps->size_a == 3)
		{
			sort_3(ps, ps->stack_a, ps->size_a);
			if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
				break ;
			if (ps->stack_b[0] < ps->stack_b[1])
				swap_b(ps);
			push_a(ps);
			if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
				break ;
			if (ps->stack_a[0] > ps->stack_a[1])
				swap_a(ps);
			if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
				break ;
			push_a(ps);
			if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
				break ;
			if (ps->stack_a[0] > ps->stack_a[1])
				swap_a(ps);
			if (is_sorted(ps->stack_a, ps->size_a) && ps->size_a == ps->full_size)
				break ;
		}

		/*for (i = 0; i < ps->size_a; i++)
			ft_printf("pos a %i: %i\n", i, ps->stack_a[i]);
		ft_printf("--UM LOOP DA PUTARIA!\n");*/
	}
			
}
