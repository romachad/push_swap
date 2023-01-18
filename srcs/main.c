/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:43:49 by romachad          #+#    #+#             */
/*   Updated: 2023/01/17 23:19:29 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/libft.h"

//#include <limits.h>
#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_ps	ps;

	if (argc <= 1)
	{
		exit (255);
	}
	check_input(&ps, argc, argv);
	int	i = 0;
	while (i < ps.arg_a)
	{
		printf("pos %i: %i\n", i, ps.stack_a[i]);
		i++;
	}
	free(ps.stack_a);
	free(ps.stack_b);
	/*printf("%d\n", INT_MAX);
	printf("%d\n", INT_MIN);
	unsigned int t;
	t = INT_MIN;
	printf("%u\n", t);
	t = 4294967295;
	printf("%u\n", t);
	int i;
	i = 2147483649;
	printf("%i\n", i);
	i = 4294967295;
	printf("%i\n", i);*/
	return (0);
}
