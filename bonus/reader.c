/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romachad <romachad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:49:27 by romachad          #+#    #+#             */
/*   Updated: 2023/02/01 02:10:25 by romachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/libft.h"

static int	exec(t_ps *ps, char *cmd)
{
	if (!ft_strncmp("sa\n", cmd, 3))
		fake_swap_a(ps);
	else if (!ft_strncmp("sb\n", cmd, 3))
		fake_swap_b(ps);
	else if (!ft_strncmp("ss\n", cmd, 3))
		fake_swap_ss(ps);
	else if (!ft_strncmp("pa\n", cmd, 3))
		fake_push_a(ps);
	else if (!ft_strncmp("pb\n", cmd, 3))
		fake_push_b(ps);
	else if (!ft_strncmp("ra\n", cmd, 3))
		fake_rotate_a(ps);
	else if (!ft_strncmp("rb\n", cmd, 3))
		fake_rotate_b(ps);
	else if (!ft_strncmp("rr\n", cmd, 3))
		fake_rotate_rr(ps);
	else if (!ft_strncmp("rra\n", cmd, 4))
		fake_rrotate_a(ps);
	else if (!ft_strncmp("rrb\n", cmd, 4))
		fake_rrotate_b(ps);
	else if (!ft_strncmp("rrr\n", cmd, 4))
		fake_rrr(ps);
	else
		return (0);
	return (1);
}

static void	clear_list(t_cmds *list)
{
	t_cmds *temp;

	while (list)
	{
		temp = list;
		list = temp->next;
		free(temp->cmd);
		free(temp);
	}
}

static void	add_command(t_cmds *list, char *line)
{
	t_cmds	*swap;
	t_cmds	*new;

	swap = list;
	while (swap->next)
		swap = swap->next;
	new = malloc(sizeof(t_cmds));
	new->cmd = ft_strdup(line);
	new->next = NULL;
	swap->next = new;
}

static void	run_commands(t_ps *ps, t_cmds *list)
{
	t_cmds *tmp;

	tmp = list;
	while (tmp->next || (tmp->next == NULL && tmp->cmd))
	{
		if (exec(ps, tmp->cmd) == 0)
		{
			free_stack(ps);
			clear_list(list);
			error(5);
		}
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	clear_list(list);
}

void	read_commands(t_ps *ps)
{
	t_cmds	*list;
	char	*line;

	line = get_next_line(0);
	if (!line)
		return ;
	list = malloc(sizeof(t_cmds));
	list->cmd = ft_strdup(line);
	list->next = NULL;
	while (1)
	{
		free(line);
		line = get_next_line(0);
		if (!line)
			break ;
		add_command(list, line);
	}
	run_commands(ps, list);
}
