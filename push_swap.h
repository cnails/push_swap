/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:04:16 by cnails            #+#    #+#             */
/*   Updated: 2020/10/05 23:33:14 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

# define B "\e[34m";
# define END "\e[0m";

typedef struct		s_stack
{
	int 			val;
	int				ind;
	int				sort;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_main
{
	t_stack 	*a;
	t_stack 	*b;
	t_stack 	*max_sort;
	int			cmd_count;
	bool		print_cmd;
	bool		flag_v;
	bool		flag_c;
	int			len_a;
	int			len_b;
	int			tmp_a;
	int			tmp_b;
	int			tmp;
}					t_main;

#endif
