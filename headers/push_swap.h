/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad </var/spool/mail/coret>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:49:08 by romachad          #+#    #+#             */
/*   Updated: 2023/01/18 22:41:24 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include <limits.h>

typedef struct s_ps
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}	t_ps;

void	check_input(t_ps *ps, int argc, char *argv[]);
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
int		check_size(int argc, char *argv[]);

#endif
