/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve5_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:49:03 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 17:49:06 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_rev_sortedl(t_list *lst, int limit)
{
	int		i;

	i = 1;
	if (limit <= 1)
		return (1);
	while (lst != NULL && lst->next != NULL && i++ < limit)
	{
		if (to_int(lst->content) < to_int(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	_part1(t_list **lst)
{
	sb(lst);
	return (1);
}

int	_part_rev(t_list **lst)
{
	if (to_int(lst[0]->content) < to_int(lst[0]->next->content)
		&& to_int(lst[0]->content) < to_int(lst[0]->next->next->content))
	{
		if (to_int(lst[0]->next->content) < to_int(lst[0]->next->next->content))
		{
			sb(lst);
			rb(lst);
			sb(lst);
			rrb(lst);
			sb(lst);
		}
		else
		{
			sb(lst);
			rb(lst);
			sb(lst);
			rrb(lst);
		}
		return (1);
	}
	else if (to_int(lst[0]->content) < to_int(lst[0]->next->content))
		return (_part1(lst));
	return (0);
}

int	resolve5rev_3(t_list **lst, int size)
{
	if (is_rev_sortedl(lst[0], 3) || size == 1)
		return (size);
	if (size == 2)
	{
		sb(lst);
		return (2);
	}
	else if (_part_rev(lst))
		return (3);
	else if (to_int(lst[0]->content) < to_int(lst[0]->next->next->content))
	{
		rb(lst);
		sb(lst);
		rrb(lst);
		sb(lst);
	}
	else
	{
		rb(lst);
		sb(lst);
		rrb(lst);
	}
	return (3);
}
