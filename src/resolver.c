/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:15:40 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 18:15:44 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get2(t_list *lst, int index)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (i == index)
			return (to_int(lst->content));
		lst = lst->next;
		i++;
	}
	return (0);
}

int	get2_best_pivot(t_list **lst, int size, int *nb)
{
	int		pivot;
	int		i;
	int		temp;
	int		count;

	i = 0;
	while (i < size)
	{
		temp = get2(lst[0], i);
		count = n_min(lst[0], temp, size);
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

void	resolve5_part(t_list **lst, t_list **lstb, int size, int *size2)
{
	int		nb;
	int		pivot;

	nb = 0;
	*size2 = 0;
	pivot = get2_best_pivot(lst, size, &nb);
	nb = n_min(lst[0], pivot, size);
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
			if (is_sorted(lst[0]))
				break ;
			ra(lst);
			if (is_sorted(lst[0]))
				break ;
		}
	}
}

int	resolve5(t_list **lst, t_list **lstb, int size)
{
	int		size2;

	if (size <= 5)
		sort_min_5(lst, lstb);
	else
	{
		resolve5_part(lst, lstb, size, &size2);
		if (!is_sorted(lst[0]))
			resolve5(lst, lstb, ft_lstsize(lst[0]));
		if (size2 != 0)
			size2 = resolve5b(lst, lstb, size2);
		while (size2-- > 0)
			pa(lst, lstb);
	}
	return (0);
}
