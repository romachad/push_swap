/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:14:42 by romachad          #+#    #+#             */
/*   Updated: 2023/01/25 03:48:14 by romachad         ###   ########.fr       */
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

static void	allocate_stack(t_ps *ps, int size, char **str)
{
	ps->size_a = size;
	ps->size_b = 0;
	ps->stack_a = ft_calloc(ps->size_a, sizeof(size));
	ps->stack_b = ft_calloc(ps->size_a, sizeof(size));
	ps->tmp = ft_calloc(ps->size_a, sizeof(size));
	ps->sorted = ft_calloc(ps->size_a, sizeof(size));
	size = -1;
	while (str[++size])
		ps->stack_a[size] = ft_atoi(str[size]);
	if (repeated_numbers(ps->stack_a, ps->size_a) == 1)
	{
		free_stack(ps);
		free_char_array(str);
		error(4);
	}
	free_char_array(str);
}

void	check_single_input(t_ps *ps, int argc, char *argv[])
{
	char	**str_n;
	int		i;

	if (check_empty(argc, argv) == -1)
		error(1);
	if (check_chars(argc, argv) == -1)
		error(2);
	i = -1;
	while (argv[1][++i] != '\0')
	{
		if ('\f' == argv[1][i] || '\n' == argv[1][i] || \
				'\t' == argv[1][i] || '\v' == argv[1][i])
			ft_memset(&argv[1][i], ' ', 1);
	}
	str_n = ft_split(argv[1], ' ');
	i = 0;
	while (str_n[i])
		i++;
	ps->flag_single = 1;
	if (check_size(ps, i, str_n) != 0)
	{
		free_char_array(str_n);
		error(3);
	}
	allocate_stack(ps, i, str_n);
}

void	check_input(t_ps *ps, int argc, char *argv[])
{
	int	i;

	if (check_empty(argc, argv) == -1)
		error(1);
	if (check_chars(argc, argv) == -1)
		error(2);
	ps->flag_single = 0;
	if (check_size(ps, argc, argv) != 0)
		error(3);
	ps->size_a = argc - 1;
	ps->size_b = 0;
	ps->stack_a = ft_calloc(ps->size_a, sizeof(int));
	ps->stack_b = ft_calloc(ps->size_a, sizeof(int));
	ps->tmp = ft_calloc(ps->size_a, sizeof(int));
	ps->sorted = ft_calloc(ps->size_a, sizeof(int));
	i = 0;
	while (argv[++i])
		ps->stack_a[i - 1] = ft_atoi(argv[i]);
	if (repeated_numbers(ps->stack_a, ps->size_a) == 1)
	{
		free_stack(ps);
		error(4);
	}
}
