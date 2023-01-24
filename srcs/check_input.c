/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:14:42 by romachad          #+#    #+#             */
/*   Updated: 2023/01/24 06:43:36 by romachad         ###   ########.fr       */
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

void	check_single_input(t_ps *ps, int argc, char *argv[])
{
	int	i;
//	char	*dup;
	char	**str_n;

	if (check_empty(argc, argv) == -1)
		error(1);
	if (check_chars(argc, argv) == -1)
		error(2);
//	dup = ft_stdup(argv[0])
	i = -1;
	//while (argv[1][0][++i] != '\0')
	while (argv[1][++i] != '\0')
	{
		//if ('\f' == argv[1][0][i] || '\n' == argv[1][0][i] || '\t' == argv[1][0][i] || '\v' == argv[1][0][i])
		if ('\f' == argv[1][i] || '\n' == argv[1][i] || '\t' == argv[1][i] || '\v' == argv[1][i])
			ft_memset(&argv[1][i], ' ', 1);
	}
	str_n = ft_split(argv[1], ' ');
	i = 0;
	while (str_n[i])
		i++;
	if (check_size(i, str_n) != 0)
		//LIBERAR MEMORIA AQUI!
		error(3);
	ps->size_a = i;
	ps->size_b = 0;
	ps->stack_a = ft_calloc(ps->size_a, sizeof(i));
	ps->stack_b = ft_calloc(ps->size_a, sizeof(i));
	ps->tmp = ft_calloc(ps->size_a, sizeof(i));
	ps->sorted = ft_calloc(ps->size_a, sizeof(i));
	i = -1;
	while (str_n[++i])
		ps->stack_a[i] = ft_atoi(str_n[i]);
	if (repeated_numbers(ps->stack_a, ps->size_a) == 1)
	{
		free(ps->stack_a);
		free(ps->stack_b);
		free(ps->tmp);
		free(ps->sorted);
		//LIBERAR STR_N
		error(4);
	}
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
		free(ps->stack_a);
		free(ps->stack_b);
		free(ps->tmp);
		free(ps->sorted);
		error(4);
	}
	//	ps->sa = malloc(5 * sizeof(int));
	//ps->sa[0] = 0;
}
