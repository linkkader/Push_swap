/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:40:53 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 17:40:57 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_part(t_list **lst)
{
	if (to_int(lst[0]->content) > to_int(lst[0]->next->content)
		&& to_int(lst[0]->content) > to_int(lst[0]->next->next->content))
	{
		if (to_int(lst[0]->next->content) > to_int(lst[0]->next->next->content))
		{
			sa(lst);
			ra(lst);
			sa(lst);
			rra(lst);
			sa(lst);
		}
		else
		{
			sa(lst);
			ra(lst);
			sa(lst);
			rra(lst);
		}
		return (1);
	}
	return (0);
}

void	resolve5_3(t_list **lst, int size)
{
	if (is_sortedl(lst[0], size) || size == 1)
		return ;
	if (size == 2)
	{
		sa(lst);
		return ;
	}
	if (_part(lst))
		return ;
	if (to_int(lst[0]->content) > to_int(lst[0]->next->content))
		sa(lst);
	else if (to_int(lst[0]->content) < to_int(lst[0]->next->next->content))
	{
		ra(lst);
		sa(lst);
		rra(lst);
	}
	else
	{
		ra(lst);
		sa(lst);
		rra(lst);
		sa(lst);
	}
}

void	resolve4_3(t_list **lst)
{
	if (is_sorted(lst[0]))
		return ;
	if (to_int(lst[0]->content) > to_int(lst[0]->next->content)
		&& to_int(lst[0]->content) > to_int(lst[0]->next->next->content))
	{
		if (to_int(lst[0]->next->content) > to_int(lst[0]->next->next->content))
		{
			sa(lst);
			rra(lst);
		}
		else
			ra(lst);
	}
	else if (to_int(lst[0]->content) > to_int(lst[0]->next->content))
		sa(lst);
	else if (to_int(lst[0]->content) < to_int(lst[0]->next->next->content))
	{
		sa(lst);
		ra(lst);
	}
	else
		rra(lst);
}

void	resolve4_5(t_list **lst, t_list **lstb)
{
	int		i;

	i = 1;
	if (is_sorted(lst[0]))
		return ;
	pa_min(lst, lstb);
	if (ft_lstsize(lst[0]) != 3)
	{
		i++;
		pa_min(lst, lstb);
	}
	resolve4_3(lst);
	while (lstb[0] && i > 0)
	{
		i--;
		pa(lst, lstb);
	}
}

void	sort_min_5(t_list **lst, t_list **lstb)
{
	int		size;

	size = ft_lstsize(lst[0]);
	if (size == 2)
		ra(lst);
	if (size == 3)
		resolve4_3(lst);
	else
		resolve4_5(lst, lstb);
}
