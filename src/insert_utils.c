/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:38:04 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 17:38:07 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lsta)
{
	void	*temp;

	if (lsta[0] == NULL || lsta[0]->next == NULL)
		return ;
	temp = lsta[0]->content;
	lsta[0]->content = lsta[0]->next->content;
	lsta[0]->next->content = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **lstb)
{
	void	*temp;

	if (lstb[0] == NULL || lstb[0]->next == NULL)
		return ;
	temp = lstb[0]->content;
	lstb[0]->content = lstb[0]->next->content;
	lstb[0]->next->content = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **lsta, t_list **lstb)
{
	sa(lsta);
	sb(lstb);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (lstb[0] == NULL)
		return ;
	temp = lstb[0];
	lstb[0] = lstb[0]->next;
	temp->next = lsta[0];
	lsta[0] = temp;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (lsta[0] == NULL)
		return ;
	temp = lsta[0];
	lsta[0] = lsta[0]->next;
	temp->next = lstb[0];
	lstb[0] = temp;
	ft_putstr_fd("pb\n", 1);
}
