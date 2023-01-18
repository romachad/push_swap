/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:14:42 by romachad          #+#    #+#             */
/*   Updated: 2023/01/17 23:44:06 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include "../headers/push_swap.h"

static int	check_chars(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] != ' ' && argv[i][j] != '\f' \
					&& argv[i][j] != '\n' \
					&& argv[i][j] != '-')
				if (argv[i][j] != '\r' && argv[i][j] != '\t' \
						&& argv[i][j] != '\v')
					if (argv[i][j] < '0' \
							|| argv[i][j] > '9')
						return (-1);
		}
	}
	return (0);
}

static int	check_empty(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == 0)
			return (-1);
	}
	return (0);
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

void	check_input(t_ps *ps, int argc, char *argv[])
{
	int	i;

	if (check_empty(argc, argv) == -1)
		error(1);
	if (check_chars(argc, argv) == -1)
		error(2);
	if (check_size(argc, argv) != 0)
		error(3);
	ps->arg_a = argc - 1;
	ps->arg_b = 0;
	ps->stack_a = ft_calloc(ps->arg_a, sizeof(int));
	ps->stack_b = ft_calloc(ps->arg_a, sizeof(int));
	i = 0;
	while (argv[++i])
		ps->stack_a[i - 1] = ft_atoi(argv[i]);
	if (repeated_numbers(ps->stack_a, ps->arg_a) == 1)
	{
		free(ps->stack_a);
		free(ps->stack_b);
		error(4);
	}
	//	ps->sa = malloc(5 * sizeof(int));
	//ps->sa[0] = 0;
}
