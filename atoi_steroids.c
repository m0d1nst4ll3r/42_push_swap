/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_steroids.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:26:28 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/27 20:21:07 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atroids(char *s, int *n, int strictness)
{
	int	i;

	if (!s || !n)
		return (1);
	while (*s && ((strictness == 1 && ft_isspace(*s))
			|| (strictness == 0 && !ft_isdigit(*s))))
		s++;
	if ((strictness == 2 && !ft_isdigit()) || (strictness == 2 && ))
	return (0);
}
