/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:08:44 by rpohlen           #+#    #+#             */
/*   Updated: 2022/01/28 11:42:19 by rpohlen          ###   ########.fr       */
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

# define S_PA	"pa\n"
# define S_PB	"pb\n"
# define S_SA	"sa\n"
# define S_SB	"sb\n"
# define S_SS	"ss\n"
# define S_RA	"ra\n"
# define S_RB	"rb\n"
# define S_RR	"rr\n"
# define S_RRA	"rra\n"
# define S_RRB	"rrb\n"
# define S_RRR	"rrr\n"

# include "libft.h"
# include <stdlib.h>

//	The beginning of the list is the top of the stack
typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

typedef struct s_instr
{
	char			op;
	struct s_instr	*next;
}					t_instr;

//	error.c
void	error_out(void);

//	args.c
t_stack	*init_stack(int ac, char **av);

//	list.c
t_stack	*add_to_stack(t_stack **stack, int num);
void	free_stack(t_stack *stack);
t_instr	*add_to_instr(t_instr **instr, char op);
void	free_instr(t_instr *instr);
void	print_stack(t_stack *stack);

//	operations.c
void	do_operation(t_stack **a, t_stack **b, char op);

//	args.c
int		args_are_valid(int ac, char **av);

//	read.c
t_instr	*read_instructions(void);

//	exec.c
void	execute_instructions(t_instr *instructions, t_stack **a, t_stack **b);

//	verif.c
int		is_sorted(t_stack *stack);

#endif
