/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 07:44:35 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/28 11:37:46 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	backwards_check(int *a, int i)
{
	int	j;

	j = i - 1;
	while (j >= 0)
	{
		if (a[i] == a[j])
			return (1);
		j--;
	}
	return (0);
}

static int	*read_args(int ac, char **av)
{
	int	*args;
	int	i;

	args = malloc((ac - 1) * sizeof(*args));
	i = 1;
	while (i < ac)
	{
		if (ft_atoi_strict(av[i], args + i - 1) || backwards_check(args, i - 1))
		{
			free(args);
			error_out();
		}
		i++;
	}
	return (args);
}

static t_stack	*fill_list(int *a, int size)
{
	t_stack	*stack;
	t_stack	*last;
	int		i;

	stack = NULL;
	last = NULL;
	i = 0;
	while (i < size)
	{
		if (last)
			last = add_to_stack(&last, a[i]);
		else
			last = add_to_stack(&stack, a[i]);
		i++;
	}
	return (stack);
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	int		*args;

	args = read_args(ac, av);
	stack = fill_list(args, ac - 1);
	return (stack);
}
