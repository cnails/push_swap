/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lennwords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:02:30 by cnails            #+#    #+#             */
/*   Updated: 2019/09/10 15:18:05 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lennwords(char *str, int n)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (n == 0)
		{
			while (str[i] != ' ' && str[i])
			{
				i++;
				a++;
			}
		}
		n--;
		while (str[i] != ' ' && str[i])
			i++;
	}
	return (a);
}
