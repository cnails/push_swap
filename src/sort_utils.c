/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:03:21 by cnails            #+#    #+#             */
/*   Updated: 2020/11/10 20:07:17 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_main *data)
{
	t_stack *a;
	int		tmp;

	if (data->b != NULL)
		return (false);
	a = data->a;
	tmp = a->val;
	while (a)
	{
		if (tmp > a->val)
			return (false);
		tmp = a->val;
		a = a->next;
	}
	return (true);
}
