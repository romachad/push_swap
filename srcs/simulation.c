/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:25:46 by romachad          #+#    #+#             */
/*   Updated: 2023/01/28 15:35:38 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	duplicate_data(t_ps *ps, t_ps *fake)
{
	int	i;
		
	i = -1;
	while (++i < ps->size_a)
		fake->stack_a[i] = ps->stack_a[i];
	i = -1;
	while (++i < ps->size_b)
		fake->stack_b[i] = ps->stack_b[i];
	fake->size_a = ps->size_a;
	fake->size_b = ps->size_b;
}

int	simulation(t_ps *ps, t_ps *fake)
{
	int	i;
	int	count;
	int	best_i;

	i = 0;
	best_i = 1;
	count = INT_MAX;
	duplicate_data(ps, fake);
	//while (++i < fake->size_b / 2)
	while (++i < 16 && i < fake->size_b / 2)
	{
		fake->count = 0;
		fake_b_to_a(fake, i);
		if (fake->count < count)
		{
			best_i = i;
			count = fake->count;
		}
		duplicate_data(ps, fake);
	}
	return (best_i);
}
