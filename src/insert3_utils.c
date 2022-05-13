/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert3_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:38:23 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 17:38:25 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst, int i)
{
	ft_lstadd_back(lst, ft_lstnew(new_int(i)));
}

void	pop(t_list **lst)
{
	if (lst[0] != NULL)
		lst[0] = lst[0]->next;
}

void	rr(t_list **lsta, t_list **lstb)
{
	ra(lsta);
	rb(lstb);
}

void	rrr(t_list **lsta, t_list **lstb)
{
	rra(lsta);
	rrb(lstb);
}

int	*new_int(int i)
{
	int	*a;

	a = malloc(sizeof(int));
	*a = i;
	return (a);
}
