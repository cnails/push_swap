/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 01:17:06 by cnails            #+#    #+#             */
/*   Updated: 2020/12/09 01:20:19 by cnails           ###   ########.fr       */
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
