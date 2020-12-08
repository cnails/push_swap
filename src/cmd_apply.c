/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 01:26:41 by cnails            #+#    #+#             */
/*   Updated: 2020/12/09 01:28:38 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (len == 2)
	{
		if (cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'a'))
			res = cmd_apply_s(&data->a);
		if (cmd[0] == 's' && (cmd[1] == 's' || cmd[1] == 'b'))
			res = cmd_apply_s(&data->b);
		if (cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'a'))
			res = cmd_apply_r(&data->a);
		if (cmd[0] == 'r' && (cmd[1] == 'r' || cmd[1] == 'b'))
			res = cmd_apply_r(&data->b);
		if (cmd[0] == 'p' && (cmd[1] == 'a' || cmd[1] == 'b'))
			res = cmd[1] == 'a' ? cmd_apply_p(&data->b, &data->a)\
			: cmd_apply_p(&data->a, &data->b);
	}
	else if (len == 3 && cmd[0] == 'r' && cmd[1] == 'r')
	{
		if (cmd[2] == 'r' || cmd[2] == 'a')
			res = cmd_apply_rr(&data->a);
		if (cmd[2] == 'r' || cmd[2] == 'b')
			res = cmd_apply_rr(&data->b);
	}
	return (res == 0 ? 0 : 1);
}
