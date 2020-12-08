/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:03:22 by cnails            #+#    #+#             */
/*   Updated: 2020/12/09 01:27:32 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*max_sort(t_stack *stack)
{
	t_stack *tmp;
	t_stack *max;
	t_stack *first;
	int		len;
	int		i;

	len = len_stack(stack);
	max = stack;
	first = stack;
	while (stack)
	{
		tmp = stack;
		i = 0;
		while (i < len)
		{
			if ((!tmp->next ? first : tmp->next)->val < tmp->val)
				break ;
			stack->sort++;
			tmp = !tmp->next ? first : tmp->next;
			i++;
		}
		max = stack->sort >= max->sort ? stack : max;
		stack = stack->next;
	}
	return (max);
}

int			iter_to_up(int stack_len, int node_ind)
{
	if (stack_len / 2 >= node_ind)
	{
		return (node_ind);
	}
	else
	{
		return (node_ind - stack_len);
	}
}

bool		is_valid_int(int nbr, char *str)
{
	char *tmp;

	tmp = ft_itoa(nbr);
	if (ft_strcmp(tmp, str))
	{
		free(tmp);
		return (false);
	}
	free(tmp);
	return (true);
}

void	parse_data(int ac, char **av, t_main *data)
{
	int i;
	int nbr;

	av = ac == 2 ? ft_strsplit(av[1], ' ') : av;
	i = ac == 2 ? 0 : 1;
	while ((ac == 2 ? ft_atoi(av[i]) : i < ac))
	{
		if (!ft_strcmp(av[i], "-v"))
			data->flag_v = true;
		else if (!ft_strcmp(av[i], "-c"))
			data->flag_c = true;
		else
		{
			nbr = ft_atoi(av[i]);
			if (!is_valid_int(nbr, av[i]) || !is_not_dupl(data->a, nbr) ||
				!(stack_push_back_int(&data->a, nbr)))
				ft_error("Not a valid arguments");
		}
		i++;
	}
	ft_free_array(ac == 2 ? av : NULL);
}

t_main		*init_data(int ac, char **av)
{
	t_main *data;

	if (!(data = (t_main *)ft_memalloc(sizeof(t_main))))
		ft_error("Failed malloc");
	parse_data(ac, av, data);
	if (!data->a)
	{
		ft_error("Invalid arguments");
	}
	data->flag_v = false;
	data->flag_c = false;
	data->print_cmd = true;
	return (data);
}

void		stack_a_init(t_main *data)
{
	int	nbr;
	int	len_max;

	indexing(data->a);
	data->max_sort = max_sort(data->a);
	data->len_a = len_stack(data->a);
	len_max = data->max_sort->ind + data->max_sort->sort;
	nbr = data->len_a - len_max > 0 ?
		len_max : ft_abs(data->len_a - len_max);
	nbr = iter_to_up(data->len_a, nbr);
	cmd_apply_cnt(data, nbr > 0 ? "ra" : "rra", nbr);
}

void		st_a_to_b(t_main *data)
{
	t_stack *stack;

	stack = data->a;
	while (stack && stack->ind != data->max_sort->ind)
	{
		stack = stack->next;
		cmd_apply_cnt(data, "pb", 1);
	}
}

int			index_node(t_stack *stack, int nbr)
{
	t_stack *tmp;
	int		min;

	min = 0;
	tmp = NULL;
	while (stack)
	{
		if ((min == 0) || (min < 0 && stack->val - nbr < 0\
		&& stack->val - nbr > min) || (min > 0 && stack->val - nbr < min))
		{
			min = stack->val - nbr;
			tmp = stack;
		}
		stack = stack->next;
	}
	if (tmp == stack && min < 0)
		return (-1);
	return (min < 0 ? tmp->ind + 1 : tmp->ind);
}

void		tmp_to_opt(t_main *data)
{
	data->opt_ind = data->tmp_ind;
	data->opt_b = data->tmp_b;
	data->opt_a = data->tmp_a;
}

int			b_to_a_count(int a, int b, int tmp)
{
	if (a > 0 && b > 0 && tmp != -1)
		return (a > b ? a : b);
	if (a < 0 && b < 0 && tmp != -1)
		return (ft_abs(a) > ft_abs(b) ? ft_abs(a) : ft_abs(b));
	else
		return (ft_abs(a) + ft_abs(b));
	
}

int			count_cmds_tmp(t_main *data, t_stack *stack)
{
	data->tmp_ind = index_node(data->a, stack->val);
	data->tmp_b = iter_to_up(data->len_b, stack->ind);
	data->tmp_a = iter_to_up(data->len_a, data->tmp_ind);
	return (b_to_a_count(data->tmp_a, data->tmp_b, data->tmp_ind));
}

void		node_b_to_a(t_main *data)
{
	data->tmp_b = ft_abs(data->opt_b);
	data->tmp_a = ft_abs(data->opt_a);
	while (((data->opt_b > 0 && data->opt_a > 0) || (data->opt_b < 0 && data->opt_a < 0)) && data->tmp_b && data->tmp_a && data->opt_ind != -1)
	{
		cmd_apply_cnt(data, data->opt_b > 0 ? "rr" : "rrr", 1);
		data->tmp_b--;
		data->tmp_a--;
	}
	cmd_apply_cnt(data, data->opt_b > 0 ? "rb" : "rrb", data->tmp_b);
	if (data->opt_ind != -1)
		cmd_apply_cnt(data, data->opt_a > 0 ? "ra" : "rra", data->tmp_a);
	cmd_apply_cnt(data, "pa", 1);
}

void		st_b_to_a(t_main *data)
{
	t_stack *stack;
	int		min;
	int		cs;

	while (data->b)
	{
		stack = data->b;
		indexing(data->a);
		indexing(data->b);
		data->len_a = len_stack(data->a);
		data->len_b = len_stack(data->b);
		min = count_cmds_tmp(data, stack);
		tmp_to_opt(data);
		while (stack)
		{
			cs = count_cmds_tmp(data, stack);
			if (cs < min)
			{
				min = cs;
				tmp_to_opt(data);
			}
			stack = stack->next;
		}
		node_b_to_a(data);
	}
}

void		st_a_min_to_top(t_main *data)
{
	t_stack		*tmp_a;
	t_stack		*min_node;
	int			cnt_to_up;

	tmp_a = data->a;
	min_node = tmp_a;
	while (tmp_a)
	{
		min_node = tmp_a->val < min_node->val ? tmp_a : min_node;
		tmp_a = tmp_a->next;
	}
	data->len_a = len_stack(data->a);
	indexing(data->a);
	cnt_to_up = iter_to_up(data->len_a, min_node->ind);
	cmd_apply_cnt(data, cnt_to_up > 0 ? "ra" : "rra", cnt_to_up);
}	

void		ft_sort(t_main *data)
{
	st_a_to_b(data);
	st_b_to_a(data);
	st_a_min_to_top(data);
}

int			main(int ac, char **av)
{
	t_main	*data;

	if (ac >= 2)
	{
		data = init_data(ac, av);
		data->len_a = len_stack(data->a);
		stack_a_init(data);
		ft_sort(data);
		free_data(&data);
	}
	return (0);
}
