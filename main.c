/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 21:03:22 by cnails            #+#    #+#             */
/*   Updated: 2020/09/18 22:25:04 by cnails           ###   ########.fr       */
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
			if (!is_valid_int(nbr, av[i]) || !is_not_dupl(data->a, nbr))
				ft_error("Not a valid arguments");
			push_back_nbr(&data->a, nbr);
		}
		i++;
	}
	print_stack(data->a);
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

int		main(int ac, char **av)
{
	t_main	*data;

	data = init_data(ac, av);
	return (0);
}
