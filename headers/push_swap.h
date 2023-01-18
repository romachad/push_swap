/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad </var/spool/mail/coret>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:49:08 by romachad          #+#    #+#             */
/*   Updated: 2023/01/17 23:23:34 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include <limits.h>

typedef struct s_ps
{
	int	*stack_a;
	int	arg_a;
	int	*stack_b;
	int	arg_b;
}	t_ps;

void	check_input(t_ps *ps, int argc, char *argv[]);
void	error(int code);
int		check_size(int argc, char *argv[]);

#endif
