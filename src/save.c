/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:04:15 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 18:04:18 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_alldigit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+' ))
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_lst_contains(int a, t_list *lst)
{
	while (lst != NULL)
	{
		if (to_int(lst->content) == a)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (0);
}

int	save_array(int ac, t_list **lst, char **av)
{
	int		i;
	int		a;

	i = 1;
	while (i < ac)
	{
		if (!is_alldigit(av[i]))
		{
			ft_lstclear(lst, free);
			return (print_error());
		}
		a = ft_atoi(av[i]);
		if (is_lst_contains(a, lst[0]))
		{
			ft_lstclear(lst, free);
			return (print_error());
		}
		push(lst, a);
		i++;
	}
	return (ft_lstsize(lst[0]));
}
