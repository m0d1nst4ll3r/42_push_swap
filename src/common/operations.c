/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:08:12 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/27 04:15:52 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	(from1 saved to tmp)
//	1. from points to from2
//	2. from1 points to to1
//	3. to points to from1
static void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

//	(elem2 saved to tmp)
//	1. elem1 points to elem3
//	2. elem2 points to elem1
//	3. list points to elem1
static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

//	1. last points to elem1
//	2. list points to elem2
//	3. elem1 points to NULL
static void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

//	1. last points to elem1
//	2. list points to last
//	3. before-last points to NULL
static void	rotate_reverse(t_stack **stack)
{
	t_stack	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	before_last->next->next = *stack;
	*stack = before_last->next;
	before_last->next = NULL;
}

void	do_operation(t_stack **a, t_stack **b, char op)
{
	if (op % PA == 0)
		push(b, a);
	if (op % PB == 0)
		push(a, b);
	if (op % SA == 0)
		swap(a);
	if (op % SB == 0)
		swap(b);
	if (op % RA == 0)
		rotate(a);
	if (op % RB == 0)
		rotate(b);
	if (op % RRA == 0)
		rotate_reverse(a);
	if (op % RRB == 0)
		rotate_reverse(b);
}
