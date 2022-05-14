/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert2_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:37:26 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 17:37:31 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_bonus(t_list **lsta)
{
	t_list	*temp;

	if (lsta[0] == NULL || lsta[0]->next == NULL)
		return ;
	temp = lsta[0];
	lsta[0] = lsta[0]->next;
	temp->next = NULL;
	ft_lstlast(lsta[0])->next = temp;
}

void	rb_bonus(t_list **lstb)
{
	t_list	*temp;

	if (lstb[0] == NULL && lstb[0]->next != NULL)
		return ;
	temp = lstb[0];
	lstb[0] = lstb[0]->next;
	temp->next = NULL;
	ft_lstlast(lstb[0])->next = temp;
}

void	rra_bonus(t_list **lsta)
{
	t_list	*temp;
	t_list	*temp2;

	if (lsta[0] == NULL || lsta[0]->next == NULL)
		return ;
	temp = lsta[0];
	while (lsta[0]->next->next != NULL)
		lsta[0] = lsta[0]->next;
	lsta[0]->next->next = temp;
	temp2 = lsta[0]->next;
	lsta[0]->next = NULL;
	lsta[0] = temp2;
}

void	rrb_bonus(t_list **lstb)
{
	t_list	*temp;
	t_list	*temp2;

	if (lstb[0] == NULL || lstb[0]->next == NULL)
		return ;
	temp = lstb[0];
	while (lstb[0]->next->next != NULL)
		lstb[0] = lstb[0]->next;
	lstb[0]->next->next = temp;
	temp2 = lstb[0]->next;
	lstb[0]->next = NULL;
	lstb[0] = temp2;
}

void	rrr_bonus(t_list **lsta, t_list **lstb)
{
	rra_bonus(lsta);
	rrb_bonus(lstb);
}
