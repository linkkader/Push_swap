/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:38:35 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 17:38:38 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max(t_list *lst, int limit)
{
	int		i;
	int		m;

	m = to_int(lst->content);
	i = 1;
	while (i++ < limit)
	{
		if (to_int(lst->next->content) > m)
			m = to_int(lst->next->content);
		lst = lst->next;
	}
	return (m);
}

int	min(t_list *lst, int limit)
{
	int		i;
	int		m;

	m = to_int(lst->content);
	i = 1;
	while (i++ < limit)
	{
		if (to_int(lst->next->content) < m)
			m = to_int(lst->next->content);
		lst = lst->next;
	}
	return (m);
}

int	okcheck(t_list **lst, t_list **lsb)
{
	if (lsb[0] == NULL || lst[0] == NULL)
		return (-1);
	if (to_int(lsb[0]->content) < to_int(lst[0]->content)
		&& is_sorted(lst[0]) && is_rev_sorted(lsb[0]))
	{
		while (lsb[0])
		{
			pa(lst, lsb);
		}
		ft_lstclear(lst, free);
		exit(0);
	}
	return (0);
}

void	pa_min(t_list **lst, t_list **lstb)
{
	int		index;
	int		size;

	size = ft_lstsize(lst[0]);
	index = index_min(lst[0]);
	if (index * 2 <= size)
	{
		while (index-- != 0)
			ra(lst);
	}
	else
	{
		while (index++ < size)
			rra(lst);
	}
	pb(lst, lstb);
}

void	pb_max(t_list **lst, t_list **lstb)
{
	int		index1;
	int		size;

	size = ft_lstsize(lstb[0]);
	index1 = index_max(lstb[0]);
	if (index1 * 2 <= size)
	{
		while (index1-- != 0)
		{
			if (index1 == 0)
				sb(lstb);
			else
				rb(lstb);
		}
	}
	else
		while (index1++ < size)
			rrb(lstb);
	pa(lst, lstb);
}
