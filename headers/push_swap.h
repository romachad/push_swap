/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad </var/spool/mail/coret>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:49:08 by romachad          #+#    #+#             */
/*   Updated: 2023/01/13 21:14:02 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_ps
{
	int	*sa;
	unsigned int	arg_a;
	int	*sb;
	unsigned int	arg_b;
}	t_ps;

void	check_input(t_ps *ps, int argc, char *argv[]);

#endif
