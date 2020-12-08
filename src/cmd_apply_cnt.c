/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_apply_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 01:28:55 by cnails            #+#    #+#             */
/*   Updated: 2020/12/09 01:29:24 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		cmd_apply_cnt(t_main *data, char *cmd, int nbr)
{
	nbr = ft_abs(nbr);
	while (nbr)
	{
		if (cmd_apply(cmd, data))
		{
			data->cmd_count++;
			if (data->print_cmd)
			{
				printf("%s\n", cmd);
			}
		}
		else
			ft_error("error cmd_apply\n");
		nbr--;
	}
}
