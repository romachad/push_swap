/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:50:46 by romachad          #+#    #+#             */
/*   Updated: 2023/01/30 23:35:26 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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
