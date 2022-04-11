/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:39:22 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 17:39:25 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_min(t_list *lst)
{
	int		i;
	int		v;
	int		min;

	i = 0;
	v = to_int(lst->content);
	min = 0;
	while (lst)
	{
		if (to_int(lst->content) < v)
		{
			v = to_int(lst->content);
			min = i;
		}
		i++;
		lst = lst->next;
	}
	return (min);
}

int	n_max(t_list *lst, int v, int limit)
{
	int		i;
	int		ii;

	i = 0;
	ii = 0;
	while (ii++ < limit)
	{
		if (to_int(lst->content) > v)
			i++;
		lst = lst->next;
	}
	return (i);
}

int	n_min(t_list *lst, int v, int limit)
{
	int		i;
	int		ii;

	i = 0;
	ii = 0;
	while (ii++ < limit)
	{
		if (to_int(lst->content) < v)
			i++;
		lst = lst->next;
	}
	return (i);
}

int	to_int(void *i)
{
	return (*(int *)(i));
}

int	index_max(t_list *lst)
{
	int		i;
	int		v;
	int		max;

	i = 0;
	v = to_int(lst->content);
	max = 0;
	while (lst)
	{
		if (to_int(lst->content) > v)
		{
			v = to_int(lst->content);
			max = i;
		}
		i++;
		lst = lst->next;
	}
	return (max);
}
