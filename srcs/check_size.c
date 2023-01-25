/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:09:48 by romachad          #+#    #+#             */
/*   Updated: 2023/01/25 04:03:21 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static char	*skip_spaces(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\f' && str[i] != '\n')
			if (str[i] != '\r' && str[i] != '\t' && str[i] != '\v')
				break ;
	}
	return ((char *) &str[i]);
}

static int	str_to_uint(char *str, char negative)
{
	unsigned int	n;
	int				i;

	i = -1;
	n = 0;
	while (++i < 10)
	{
		n = (n * 10) + (*str - 0x30);
		str++;
	}
	if (negative == 1)
	{
		if (n > 2147483648)
			return (-1);
		else
			return (0);
	}
	else
	{
		if (n > 2147483647)
			return (-1);
		else
			return (0);
	}
}

static int	check_overflow(char *str)
{
	char	negative;

	str = skip_spaces(str);
	if (*str == '-')
	{
		str++;
		negative = 1;
	}
	else
		negative = 0;
	if (*str > '2')
		return (-1);
	else if (*str == '2')
		return (str_to_uint(str, negative));
	else
		return (0);
}

static int	iterate_str(int i, int argc, char *argv[])
{
	char	*str;
	int		count;

	while (++i < argc)
	{
		count = 0;
		str = skip_spaces(argv[i]);
		if (*str == '-')
			str++;
		if (*str < '0' || *str > '9')
			return (-1);
		while (*str >= '0' && *str <= '9')
		{
			count++;
			str++;
		}
		if (count > 10)
			return (-2);
		else if (count == 10)
			count = check_overflow(argv[i]);
		if (count < 0)
			return (-2);
	}
	return (0);
}

int	check_size(t_ps *ps, int argc, char *argv[])
{
	int		i;

	if (ps->flag_single == 0)
		i = 0;
	else
		i = -1;
	return (iterate_str(i, argc, argv));
}
