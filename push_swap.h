/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:04:16 by cnails            #+#    #+#             */
/*   Updated: 2020/09/30 23:29:25 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

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
	bool		flag_v;
	bool		flag_c;
	int			len_a;
	int			len_b;
	int			tmp_a;
	int			tmp_b;
	int			tmp;
}					t_main;

#endif
