/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:03:22 by cnails            #+#    #+#             */
/*   Updated: 2020/10/01 01:12:23 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_error(char *str)
{
	printf("Error: %s\n", str);
	exit(1);
}

void		print_stack(t_stack *stack)
{
	t_stack *head;

	head = stack;
	while (head)
	{
		printf("%d\n", head->val);
		head = head->next;
	}
}

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

void		indexing(t_stack *stack)
{
	int		i;
	t_stack *head;

	i = 0;
	head = stack;
	while (head)
	{
		head->ind = i;
		i++;
		head = head->next;
	}
}

size_t		len_stack(t_stack *stack)
{
	t_stack		*head;
	size_t		i;

	i = 0;
	head = stack;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
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

t_stack		*get_last(t_stack *tmp)
{
	t_stack *stack;

	stack = tmp;
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack		*create_new(int nbr)
{
	t_stack *stack;

	if (!(stack = (t_stack *)ft_memalloc(sizeof(t_stack))))
		ft_error("malloc is failed");
	stack->val = nbr;
	stack->sort = 1;
	return (stack);
}

void		push_back(t_stack **head, t_stack *stack)
{
	if (!(*head))
		*head = stack;
	else
	{
		stack->next = *head;
		*head = stack;
	}
}

void		push_back_nbr(t_stack **head, int nbr)
{
	t_stack *stack;

	stack = create_new(nbr);
	push_back(head, stack);
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
	return (true);
}

bool		is_not_dupl(t_stack *stack, int nbr)
{
	t_stack *head;

	head = stack;
	while (head)
	{
		if (head->val == nbr)
			return (false);
		head = head->next;
	}
	return (true);
}

static void	parse_data(int ac, char **av, t_main *data)
{
	int i;
	int nbr;

	av = ac == 2 ? ft_strsplit(av[1], ' ') : av;
	i = ac == 2 ? 0 : 1;
	while ((ac == 2 ? (int)av[i] : i < ac))
	{
		if (!ft_strcmp(av[i], "-v"))
			data->flag_v = true;
		else if (!ft_strcmp(av[i], "-c"))
			data->flag_c = true;
		else
		{
			nbr = ft_atoi(av[i]);
			if (!is_valid_int(nbr, av[i]) || !is_not_dupl(data->a, nbr) ||
				!(stack_push_int(&data->a, nbr)))
				ft_error("Not a valid arguments");
			push_back_nbr(&data->a, nbr);
		}
		i++;
	}
	print_stack(data->a);
	ft_free_array(ac == 2 ? av : NULL);
}

t_main		*init_data(int ac, char **av)
{
	t_main *data;

	if (!(data = (t_main *)ft_memalloc(sizeof(t_main))))
		ft_error("malloc is failed");
	parse_data(ac, av, data);
	data->flag_v = false;
	data->flag_c = false;
	return (data);
}

t_stack		*stack_pop(t_stack **stack)
{
	t_stack *tmp;

	if (!(*stack))
		return (NULL);
	tmp = *stack;
	if (!(*stack)->next)
		*stack = NULL;
	else
		*stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

t_stack		*stack_push(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	last = get_last(*stack);
	last->next = new;
}

t_stack		*stack_push_int(t_stack **stack, int nbr)
{
	t_stack *new;

	new = create_new(nbr);
	stack_push(stack, new);
	return (*stack);
}

t_stack		*stack_shift(t_stack **stack, t_stack *new)
{
	if (!(*stack))
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

t_stack		*stack_unshift(t_stack **stack)
{
	t_stack *pre_last;
	t_stack	*tmp;

	pre_last = *stack;
	tmp = *stack;
	if (!(*stack))
		return (NULL);
	if (!(*stack)->next)
		*stack = NULL;
	else
	{
		while (pre_last->next && pre_last->next->next)
			pre_last = pre_last->next;
		tmp = pre_last->next;
		pre_last->next = NULL;
	}
	return (tmp);
}

int			cmd_apply_s(t_stack **stack)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->val;
		(*stack)->val = (*stack)->next->val;
		(*stack)->next->val = tmp;
		return (1);
	}
	return (-1);
}

int			cmd_apply_r(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		stack_shift(stack, stack_unshift(stack));
		return (1);
	}
	return (-1);
}

int			cmd_apply_rr(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		stack_push(stack, stack_pop(stack));
		return (1);
	}
	return (-1);
}

int			cmd_apply_p(t_stack **start, t_stack **end)
{
	if (*start)
	{
		stack_push(end, stack_unshift(start));
		return (1);
	}
	return (-1);
}

int			cmd_apply(char *cmd, t_main *data)
{
	int len;
	int res;

	len = ft_strlen(cmd);
	res = 0;
	if (len == 2 && cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'a'))
		res = cmd_apply_s(&data->a);
	if (len == 2 && cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'b'))
		res = cmd_apply_s(&data->b);
	if (len == 2 && cmd[0] == 'p' && cmd[1] == 'a')
		res = cmd_apply_p(&data->b, &data->a);
	if (len == 2 && cmd[0] == 'p' && cmd[1] == 'b')
		res = cmd_apply_p(&data->a, &data->b);
	if (len == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'a'))
		res = cmd_apply_r(&data->a);
	if (len == 2 && cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'b'))
		res = cmd_apply_r(&data->b);
	if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r' &&
		(cmd[2] == 'r' || cmd[2] == 'a'))
		res = cmd_apply_rr(&data->a);
	if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r' &&
		(cmd[2] == 'r' || cmd[2] == 'b'))
		res = cmd_apply_rr(&data->b);
	return (res == 0 ? 0 : 1);
}

void		cmd_apply_cnt(t_main *data, char *cmd, int nbr)
{
	nbr = ft_abs(nbr);
	while (nbr)
	{
		if (cmd_apply(cmd, data))
		{
			data->cmd_count++;
		}
		else
			ft_error("error cmp_apply\n");
		nbr--;
	}
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

int		main(int ac, char **av)
{
	t_main	*data;

	data = init_data(ac, av);
	data->len_a = len_stack(data->a);
	stack_a_init(data);
	return (0);
}
