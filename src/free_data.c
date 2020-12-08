/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:57:17 by cnails            #+#    #+#             */
/*   Updated: 2020/12/09 00:44:46 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void		free_data(t_main **data)
{
	if (*data)
	{
		if ((*data)->a)
			free_stack(&(*data)->a);
		if ((*data)->b)
			free_stack(&(*data)->b);
		free(*data);
	}
}
