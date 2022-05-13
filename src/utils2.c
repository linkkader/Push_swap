/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:38:49 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 17:39:13 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_rev_sorted(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		if (to_int(lst->content) < to_int(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_sorted(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		if (to_int(lst->content) > to_int(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_it_min(t_list *lst, int min)
{
	while (lst)
	{
		if (to_int(lst->content) < min)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_it_max(t_list *lst, int max)
{
	while (lst)
	{
		if (to_int(lst->content) > max)
			return (0);
		lst = lst->next;
	}
	return (1);
}
