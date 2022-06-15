/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:13:57 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/28 11:40:30 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	prev;

	prev = stack->num;
	while (stack)
	{
		if (stack->num < prev)
			return (0);
		prev = stack->num;
		stack = stack->next;
	}
	return (1);
}
