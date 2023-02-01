/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:29:22 by romachad          #+#    #+#             */
/*   Updated: 2023/02/01 02:09:43 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/libft.h"

int	main(int argc, char *argv[])
{
	t_ps	ps;

	if (argc < 2)
		exit (255);
	else if (argc == 2)
		check_single_input(&ps, argc, argv);
	else
		check_input(&ps, argc, argv);
	ps.full_size = ps.size_a;
	read_commands(&ps);
	if (is_sorted(ps.stack_a, ps.size_a) && ps.size_a == ps.full_size)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&ps);
}
