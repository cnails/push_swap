/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:04:16 by cnails            #+#    #+#             */
/*   Updated: 2020/12/09 00:39:50 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

# define B "\e[34m"
# define END "\e[0m"

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
	int			tmp_ind;
	bool		flag_v;
	bool		flag_c;
	int			len_a;
	int			len_b;
	int			opt_b;
	int			opt_a;
	int			opt_ind;
	int			tmp_a;
	int			tmp_b;
	int			tmp;
}					t_main;

t_stack		*stack_push_int(t_stack **stack, int nbr);
void		ft_error(char *str);
void		print_stack(t_stack *stack);
size_t		len_stack(t_stack *stack);
t_stack		*max_sort(t_stack *stack);
void		indexing(t_stack *stack);
int			iter_to_up(int stack_len, int node_ind);
t_stack		*get_last(t_stack *tmp);
t_stack		*create_new(int nbr);
void		push_back(t_stack **head, t_stack *stack);
void		push_back_nbr(t_stack **head, int nbr);
bool		is_valid_int(int nbr, char *str);
void		stack_push_back(t_stack **stack, t_stack *new);
t_stack		*stack_push_back_int(t_stack **stack, int nbr);
bool		is_not_dupl(t_stack *stack, int nbr);
static void	parse_data(int ac, char **av, t_main *data);
t_main		*init_data(int ac, char **av);
t_stack		*stack_unshift(t_stack **stack);
void		stack_shift(t_stack **stack, t_stack *new);
void		stack_push(t_stack **stack, t_stack *new);
t_stack		*stack_pop(t_stack **stack);
int			cmd_apply_s(t_stack **stack);
int			cmd_apply_r(t_stack **stack);
int			cmd_apply_rr(t_stack **stack);
int			cmd_apply_p(t_stack **start, t_stack **end);
int			cmd_apply(char *cmd, t_main *data);
void		cmd_apply_cnt(t_main *data, char *cmd, int nbr);
void		stack_a_init(t_main *data);
void		st_a_to_b(t_main *data);
int			index_node(t_stack *stack, int nbr);
void		tmp_to_opt(t_main *data);
int			b_to_a_count(int a, int b, int tmp);
int			count_cmds_tmp(t_main *data, t_stack *stack);
void		node_b_to_a(t_main *data);
void		st_b_to_a(t_main *data);
void		st_a_min_to_top(t_main *data);
void		ft_sort(t_main *data);
void		free_data(t_main **data);
bool		is_sorted(t_main *data);

#endif
