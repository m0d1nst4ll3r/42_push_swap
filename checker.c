/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:42:19 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/28 11:29:26 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_instr	*instructions;

	if (ac < 2)
		return (0);
	stack_a = init_stack(ac, av);
	instructions = read_instructions();
	stack_b = NULL;
	execute_instructions(instructions, &stack_a, &stack_b);
	free(instructions);
	if (stack_b || !is_sorted(stack_a))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
