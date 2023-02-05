/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:43:49 by romachad          #+#    #+#             */
/*   Updated: 2023/02/05 03:15:01 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/libft.h"

static void	sort(t_ps *ps, t_ps *fake)
{
	ps->full_size = ps->size_a;
	fake->stack_a = malloc(ps->full_size * sizeof(ps->full_size));
	fake->stack_b = malloc(ps->full_size * sizeof(ps->full_size));
	fake->tmp = malloc(ps->full_size * sizeof(ps->full_size));
	fake->sorted = malloc(ps->full_size * sizeof(ps->full_size));
	if (is_sorted(ps->stack_a, ps->size_a))
		return ;
	if (ps->size_a > 5)
		push_30pct(ps);
	if (ps->size_a == 3)
		sort_3(ps, ps->stack_a, ps->size_a);
	else if (ps->size_a == 2 && is_sorted(ps->stack_a, ps->size_a) == 0)
		swap_a(ps);
	else if (is_sorted(ps->stack_a, ps->size_a) == 0 && ps->size_a > 3)
		sort_5(ps);
	from_b_to_a(ps, fake);
	if (is_sorted(ps->stack_a, ps->size_a) == 0)
		put_smallest_top(ps);
}

int	main(int argc, char *argv[])
{
	t_ps	ps;
	t_ps	fake;

	if (argc < 2)
	{
		exit (255);
	}
	else if (argc == 2)
		check_single_input(&ps, argc, argv);
	else
		check_input(&ps, argc, argv);
	sort(&ps, &fake);
	free_stack(&ps);
	free_stack(&fake);
	return (0);
}
