/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad </var/spool/mail/coret>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:14:42 by romachad          #+#    #+#             */
/*   Updated: 2023/01/13 21:30:07 by romachad         ###   ########.fr       */
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
			if (argv[i][j] != ' ' && argv[i][j] != '\f' && argv[i][j] != '\n')
				if (argv[i][j] != '\r' && argv[i][j] != '\t' && argv[i][j] != '\v')
					if (argv[i][j] < '0' || argv[i][j] > '9')
						return (-1);
		}
	}
	return (0);
}

void	check_input(t_ps *ps, int argc, char *argv[])
{
	int	error;

	error = check_chars(argc, argv);
	if (error == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	else
		ps->sa = malloc(5 * sizeof(int));
	ps->sa[0] = 0;
}
