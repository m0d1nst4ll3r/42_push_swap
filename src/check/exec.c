/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:12:40 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/28 11:34:05 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_instructions(t_instr *instructions, t_stack **a, t_stack **b)
{
	while (instructions)
	{
		do_operation(a, b, instructions->op);
		instructions = instructions->next;
	}
}
