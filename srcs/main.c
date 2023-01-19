/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:43:49 by romachad          #+#    #+#             */
/*   Updated: 2023/01/19 01:53:10 by romachad         ###   ########.fr       */
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
	while (i < ps.size_a)
	{
		printf("pos %i: %i\n", i, ps.stack_a[i]);
		i++;
	}
	printf("\nLETS GO;\n");

	rotate_a(&ps);
	rotate_a(&ps);
	rotate_a(&ps);
	rotate_a(&ps);
	push_b(&ps);
	push_b(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	push_b(&ps);
	push_b(&ps);
	push_b(&ps);
	rotate_a(&ps);
	rotate_a(&ps);
	rotate_a(&ps);
	push_b(&ps);
	/*for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);*/
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);

	//second round
	push_b(&ps);
	push_b(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	rotate_a(&ps);
	rotate_a(&ps);
	rotate_a(&ps);
	push_b(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);

	rotate_a(&ps);
	//for (i = 0; i < ps.size_a; i++)
	//	printf("pos a %i: %i\n", i, ps.stack_a[i]);
	//for (i = 0; i < ps.size_b; i++)
	//	printf("pos b %i: %i\n", i, ps.stack_b[i]);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);

	//terceiro
	rotate_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	push_b(&ps);
	
	rotate_a(&ps);
	rotate_a(&ps);
	//for (i = 0; i < ps.size_a; i++)
	//	printf("pos a %i: %i\n", i, ps.stack_a[i]);
	//for (i = 0; i < ps.size_b; i++)
	//	printf("pos b %i: %i\n", i, ps.stack_b[i]);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);

	//quarto
	push_b(&ps);
	rotate_a(&ps);
	rotate_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	push_b(&ps);
	rotate_a(&ps);
	rotate_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	rotate_a(&ps);
	push_b(&ps);
	//for (i = 0; i < ps.size_a; i++)
	//	printf("pos a %i: %i\n", i, ps.stack_a[i]);
	//for (i = 0; i < ps.size_b; i++)
	//	printf("pos b %i: %i\n", i, ps.stack_b[i]);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);








	/*printf("\nswap a\n");
	swap_a(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	printf("\npush b:\n");
	push_b(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);
//	printf("size A and B: %i, %i", ps.size_a, ps.size_b);

	push_b(&ps);
	push_b(&ps);
	push_b(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);
	printf("size A and B: %i, %i\n", ps.size_a, ps.size_b);
	
	push_b(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);
	printf("size A and B: %i, %i\n", ps.size_a, ps.size_b);


	printf("teste de over?\n");
	push_b(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);
	printf("size A and B: %i, %i\n", ps.size_a, ps.size_b);

	printf("ROLLBACK\n\n");
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	push_a(&ps);
	swap_b(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);
	printf("size A and B: %i, %i\n", ps.size_a, ps.size_b);

	printf("\nblz, vamo pros demais\n\n");
	push_b(&ps);
	push_b(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);
	swap_b(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);
	swap_ss(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);

	rotate_a(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);

	push_b(&ps);
	rotate_b(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);

	rotate_rr(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);


	rrotate_b(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);

	rrr(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);

	push_a(&ps);
	rrotate_a(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos a %i: %i\n", i, ps.stack_a[i]);
	for (i = 0; i < ps.size_b; i++)
		printf("pos b %i: %i\n", i, ps.stack_b[i]);*/
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
