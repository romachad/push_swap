/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad </var/spool/mail/coret>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:49:08 by romachad          #+#    #+#             */
/*   Updated: 2023/01/25 04:15:48 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_ps
{
	int	*stack_a;
	int	size_a;
	int	ra;
	int	*stack_b;
	int	size_b;
	int	*tmp;
	int	*sorted;
	int	full_size;
	int	flag_single;
	int	rb;
	int	comp_bit;
	int	loop;
}	t_ps;

void	check_input(t_ps *ps, int argc, char *argv[]);
void	check_single_input(t_ps *ps, int argc, char *argv[]);
void	error(int code);
void	swap_a(t_ps *ps);
void	swap_b(t_ps *ps);
void	swap_ss(t_ps *ps);
void	push_a(t_ps *ps);
void	push_b(t_ps *ps);
void	rotate_a(t_ps *ps);
void	rotate_b(t_ps *ps);
void	rotate_rr(t_ps *ps);
void	rrotate_a(t_ps *ps);
void	rrotate_b(t_ps *ps);
void	rrr(t_ps *ps);
void	push_30pct(t_ps *ps);
void	fill_sorted(t_ps *ps);
void	fill_tmp(t_ps *ps);
void	sort_5(t_ps *ps);
void	from_b_to_a(t_ps *ps);
void	put_smallest_top(t_ps *ps);
void	sort_3(t_ps *ps, int *stack, int size);
void	free_stack(t_ps *ps);
void	*free_char_array(char **array);
int		repeated_numbers(int *array, int total);
int		biggest(int *stack, int size, int n);
int		check_size(t_ps *ps, int argc, char *argv[]);
int		is_sorted(int *stack, int size);

#endif
