/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:17:13 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/28 11:43:56 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	read_op(char *op)
{
	if (!ft_strcmp(op, S_PA))
		return (PA);
	else if (!ft_strcmp(op, S_PB))
		return (PB);
	else if (!ft_strcmp(op, S_SA))
		return (SA);
	else if (!ft_strcmp(op, S_SB))
		return (SB);
	else if (!ft_strcmp(op, S_SS))
		return (SS);
	else if (!ft_strcmp(op, S_RA))
		return (RA);
	else if (!ft_strcmp(op, S_RB))
		return (RB);
	else if (!ft_strcmp(op, S_RR))
		return (RR);
	else if (!ft_strcmp(op, S_RRA))
		return (RRA);
	else if (!ft_strcmp(op, S_RRB))
		return (RRB);
	else if (!ft_strcmp(op, S_RRR))
		return (RRR);
	return (0);
}

t_instr	*read_instructions(void)
{
	char	*line;
	t_instr	*instr;
	t_instr	*last;
	char	op;

	instr = NULL;
	last = NULL;
	line = get_next_line(0);
	while (line)
	{
		op = read_op(line);
		if (!op)
		{
			free_instr(instr);
			error_out();
		}
		if (last)
			last = add_to_instr(&last, op);
		else
			last = add_to_instr(&instr, op);
		line = get_next_line(0);
	}
	return (instr);
}
