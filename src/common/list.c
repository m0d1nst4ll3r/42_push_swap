/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:48:48 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/28 11:29:29 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instr	*add_to_instr(t_instr **instr, char op)
{
	t_instr	*last;
	t_instr	*new;

	new = malloc(sizeof(*new));
	new->op = op;
	new->next = NULL;
	if (!*instr)
		*instr = new;
	else
	{
		last = *instr;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (new);
}

void	free_instr(t_instr *instr)
{
	t_instr	*tmp;

	while (instr)
	{
		tmp = instr->next;
		free(instr);
		instr = tmp;
	}
}

t_stack	*add_to_stack(t_stack **stack, int num)
{
	t_stack	*last;
	t_stack	*new;

	new = malloc(sizeof(*new));
	new->num = num;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (new);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

//debug function
void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d", stack->num);
		stack = stack->next;
		if (stack)
			ft_printf(" ");
	}
}
