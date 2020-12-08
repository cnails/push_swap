/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 01:21:46 by cnails            #+#    #+#             */
/*   Updated: 2020/12/09 01:23:47 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void		stack_push_back(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (!(*stack))
	{
		*stack = new;
	}
	else
	{
		last = get_last(*stack);
		last->next = new;
	}
}

t_stack		*stack_push_back_int(t_stack **stack, int nbr)
{
	t_stack *new;

	new = create_new(nbr);
	stack_push_back(stack, new);
	return (*stack);
}

void		stack_push(t_stack **stack, t_stack *new)
{
	if (!(*stack))
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}
