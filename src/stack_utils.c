/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 01:24:28 by cnails            #+#    #+#             */
/*   Updated: 2020/12/09 01:26:17 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*stack_unshift(t_stack **stack)
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

void		stack_shift(t_stack **stack, t_stack *new)
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

t_stack		*stack_pop(t_stack **stack)
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
