/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:07:36 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 18:07:39 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	resolve5a_part(t_list **lst, t_list **lstb, int *size, int *size2)
{
	int		pivot;
	int		r;
	int		nb;

	r = 0;
	nb = 0;
	*size2 = 0;
	pivot = get2_best_pivot(lst, *size, &nb);
	nb = n_min(lst[0], pivot, *size);
	*size = *size - nb;
	while (nb > 0)
	{
		if (to_int(lst[0]->content) < pivot)
		{
			pb(lst, lstb);
			nb--;
			(*size2)++;
		}
		else
		{
			r++;
			ra(lst);
		}
	}
	return (r);
}

int	is_sortedl(t_list *lst, int limit)
{
	int		i;

	i = 1;
	if (limit <= 1)
		return (1);
	while (lst != NULL && lst->next != NULL && i++ < limit)
	{
		if (to_int(lst->content) > to_int(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	_part_resolvera(t_list **lst, t_list **lstb, int r)
{
	if (okcheck(lst, lstb))
		return (-1);
	while (to_int(lst[0]->content) != r)
		pa(lst, lstb);
	if (okcheck(lst, lstb))
	{
		return (-1);
	}
	return (0);
}

int	resolve5a(t_list **lst, t_list **lstb, int size)
{
	int		r;
	int		size2;
	int		size3;

	size3 = size;
	if (size <= 3)
		resolve5_3(lst, size);
	else
	{
		r = resolve5a_part(lst, lstb, &size, &size2);
		while (r-- > 0)
			rra(lst);
		if (!is_sortedl(lst[0], size))
			resolve5a(lst, lstb, size);
		if (size2 != 0)
		{
			r = min(lstb[0], size2);
			size2 = resolve5b(lst, lstb, size2);
		}
		if (_part_resolvera(lst, lstb, r))
			return (-1);
	}
	return (size3);
}
