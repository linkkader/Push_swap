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

void	sa_bonus(t_list **lsta)
{
	void	*temp;

	if (lsta[0] == NULL || lsta[0]->next == NULL)
		return ;
	temp = lsta[0]->content;
	lsta[0]->content = lsta[0]->next->content;
	lsta[0]->next->content = temp;
}

void	sb_bonus(t_list **lstb)
{
	void	*temp;

	if (lstb[0] == NULL || lstb[0]->next == NULL)
		return ;
	temp = lstb[0]->content;
	lstb[0]->content = lstb[0]->next->content;
	lstb[0]->next->content = temp;
}

void	ss_bonus(t_list **lsta, t_list **lstb)
{
	sa_bonus(lsta);
	sb_bonus(lstb);
}

void	pa_bonus(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (lstb[0] == NULL)
		return ;
	temp = lstb[0];
	lstb[0] = lstb[0]->next;
	temp->next = lsta[0];
	lsta[0] = temp;
}

void	pb_bonus(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (lsta[0] == NULL)
		return ;
	temp = lsta[0];
	lsta[0] = lsta[0]->next;
	temp->next = lstb[0];
	lstb[0] = temp;
}
