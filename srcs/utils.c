/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:50:46 by romachad          #+#    #+#             */
/*   Updated: 2023/01/28 02:44:04 by coret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	put_smallest_top(t_ps *ps)
{
	int	n;
	int	i;

	n = ps->stack_a[0];
	i = -1;
	while (++i < ps->size_a)
	{
		if (n > ps->stack_a[i])
			n = ps->stack_a[i];
	}
	i = -1;
	while (ps->stack_a[++i] != n)
		;
	if (i <= (ps->size_a / 2))
	{
		while (ps->stack_a[0] != n)
			rotate_a(ps);
	}
	else
	{
		while (ps->stack_a[0] != n)
			rrotate_a(ps);
	}
}

void	fake_put_smallest_top(t_ps *ps)
{
	int	n;
	int	i;

	n = ps->stack_a[0];
	i = -1;
	while (++i < ps->size_a)
	{
		if (n > ps->stack_a[i])
			n = ps->stack_a[i];
	}
	i = -1;
	while (ps->stack_a[++i] != n)
		;
	if (i <= (ps->size_a / 2))
	{
		while (ps->stack_a[0] != n)
			fake_rotate_a(ps);
	}
	else
	{
		while (ps->stack_a[0] != n)
			fake_rrotate_a(ps);
	}
}

int	repeated_numbers(int *array, int total)
{
	int	i;
	int	j;

	i = -1;
	while (++i < total - 1)
	{
		j = i;
		while (++j < total)
		{
			if (array[i] == array[j])
				return (1);
		}
	}
	return (0);
}

void	*free_char_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	return (0);
}

void	free_stack(t_ps *ps)
{
	free(ps->stack_a);
	free(ps->stack_b);
	free(ps->tmp);
	free(ps->sorted);
}
