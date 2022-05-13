/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolverb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:12:39 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 18:12:42 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get2_best_pivot2(t_list **lst, int size, int *nb)
{
	int		pivot;
	int		i;
	int		temp;
	int		count;

	i = 0;
	while (i < size)
	{
		temp = get2(lst[0], i);
		count = n_max(lst[0], temp, size);
		pivot = temp;
		if (count == size / 2)
		{
			*nb = count;
			break ;
		}
		i++;
	}
	return (pivot);
}

int	resolve5b_part(t_list **lst, t_list **lstb, int *size, int *size2)
{
	int		r;
	int		pivot;
	int		nb;

	r = 0;
	pivot = get2_best_pivot2(lstb, *size, &nb);
	nb = n_max(lstb[0], pivot, *size);
	*size = *size - nb;
	while (nb > 0)
	{
		if (to_int(lstb[0]->content) > pivot)
		{
			pa(lst, lstb);
			nb--;
			(*size2)++;
		}
		else
		{
			r++;
			rb(lstb);
		}
	}
	return (r);
}

int	resolve5b(t_list **lst, t_list **lstb, int size)
{
	int		r;
	int		size2;
	int		size3;
	int		m;

	size2 = 0;
	size3 = size;
	if (size <= 3)
		resolve5rev_3(lstb, size);
	else
	{
		m = max(lstb[0], size);
		r = resolve5b_part(lst, lstb, &size, &size2);
		while (r-- > 0)
			rrb(lstb);
		if (!is_rev_sortedl(lstb[0], size))
			resolve5b(lst, lstb, size);
		if (size2 > 0)
		{
			resolve5a(lst, lstb, size2);
			while (lstb[0] && to_int(lstb[0]->content) != m)
				pb(lst, lstb);
		}
	}
	return (size3);
}
