/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:08:44 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/27 04:15:49 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//	We are using prime factorial to encode and decode operation IDs
//	Since SS is both SA and SB, we can use factorial modulos to make
//		SS do both
//	Ex:
//		if (code % SA == 0)
//			do SA
//		if (code % SB == 0)
//			do SB
//	No other code but SA and SS (SA * SB) will do SA
//	No other code but SB and SS (SB * SA) will do SB
//	Codes are chosen to never exceed 127 (char)
# define PA		17
# define PB		19
# define SA		2
# define SB		13
# define SS		26 //SA * SB
# define RA		3
# define RB		11
# define RR		33 //RA * RB
# define RRA	5
# define RRB	7
# define RRR	35 //RRA * RRB

# include "libft.h"
# include <stdlib.h>

//	The beginning of the list is the top of the stack
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

//	list.c
void	add_to_stack(t_stack **stack, int num);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);

//	operations.c
void	do_operation(t_stack **a, t_stack **b, char op);

//	check.c
int		args_are_valid(int ac, char **av);

//	args.c

#endif
