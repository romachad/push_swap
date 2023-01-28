/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:43:49 by romachad          #+#    #+#             */
/*   Updated: 2023/01/28 15:07:17 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/libft.h"
#include "../headers/ft_printf.h"

//#include <limits.h>
#include <stdio.h>
//printf("b[0]: %i\n", ps->stack_b[0]);
//printf("b[1]: %i\n", ps->stack_b[1]);
//printf("b[size_b -1]: %i\n",ps->stack_b[ps->size_b -1]);
//printf("a[0]: %i\n", ps->stack_a[0]);
//printf("a[1]: %i\n", ps->stack_a[1]);
//printf("a[size_a -1]: %i\n",ps->stack_a[ps->size_a -1]);


int	main(int argc, char *argv[])
{
	t_ps	ps;
	t_ps	fake;

	if (argc < 2)
	{
		exit (255);
	}
	else if (argc == 2)
		check_single_input(&ps, argc, argv);
	else
		check_input(&ps, argc, argv);
	ps.full_size = ps.size_a;
	fake.stack_a = malloc(ps.full_size * sizeof(ps.full_size));
	fake.stack_b = malloc(ps.full_size * sizeof(ps.full_size));
	fake.tmp = malloc(ps.full_size * sizeof(ps.full_size));
	fake.sorted = malloc(ps.full_size * sizeof(ps.full_size));
	int	i = 0;/*
	while (i < ps.size_a)
	{
		printf("pos %i: %i\n", i, ps.stack_a[i]);
		i++;
	}
	printf("\nLETS GO;\n");
	printf("is sorted: %d\n", is_sorted(ps.stack_a, ps.size_a));*/
	//fill_sorted(&ps);
	//fill_tmp(&ps);
	//for (i = 0; i < ps.size_a; i++)
	//	ft_printf("pos a %i: %i\n", i, ps.stack_a[i]);
	//for (i = 0; i < ps.size_b; i++)
	//	ft_printf("pos b %i: %i\n", i, ps.stack_b[i]);
	//for (i = 0; i < ps.size_a; i++)
	//	ft_printf("pos sorted %i: %i\n", i, ps.sorted[i]);
	//for (i = 0; i < ps.size_a; i++)
	//	ft_printf("pos tmp %i: %i\n", i, ps.tmp[i]);
	//ft_printf("--INICIANDO----\n");
	if (ps.size_a > 5)
		push_30pct(&ps);
	ft_printf("-----Acabou os 30%!!!\n");	
	if (ps.size_a == 3)
		sort_3(&ps, ps.stack_a, ps.size_a);
	else if (ps.size_a == 2 && is_sorted(ps.stack_a, ps.size_a) == 0)
		swap_a(&ps);
	else if (is_sorted(ps.stack_a, ps.size_a) == 0 && ps.size_a > 3)
		sort_5(&ps);
	//for (i = 0; i < ps.size_a; i++)
	//	ft_printf("pos a %i: %i\n", i, ps.stack_a[i]);
	//for (i = 0; i < ps.size_b; i++)
	//	ft_printf("pos b %i: %i\n", i, ps.stack_b[i]);
	//for (i = 0; i < ps.size_a; i++)
	//	printf("pos sorted %i: %i\n", i, ps.sorted[i]);
	//for (i = 0; i < ps.size_a; i++)
	//	printf("pos tmp %i: %i\n", i, ps.tmp[i]);
	//printf("--FROM B TO A----\n");
	ft_printf("----Iniciando o from b to a\n");
	//from_b_to_a(&ps);
	from_b_to_a(&ps, &fake);
	ft_printf("----END of from b to a\n");
	//INCLUIR MAIS UMA VERIFICACAO? smallest to top maybe?
	if (is_sorted(ps.stack_a, ps.size_a) == 0)
		put_smallest_top(&ps);
	ft_printf("CABOU----\n");
	for (i = 0; i < ps.size_a; i++)
		ft_printf("pos a %i: %i\n", i, ps.stack_a[i]);
	ft_printf("\nis sorted: %d\n", is_sorted(ps.stack_a, ps.size_a));
	fill_sorted(&ps);
	fill_tmp(&ps);
	for (i = 0; i < ps.size_a; i++)
		printf("pos tmp %i: %i\n", i, ps.tmp[i]);
	free(ps.stack_a);
	free(ps.stack_b);
	free(ps.tmp);
	free(ps.sorted);
	free(fake.stack_a);
	free(fake.stack_b);
	free(fake.tmp);
	free(fake.sorted);
	return (0);
}
