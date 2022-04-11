
#include "push_swap.h"

void	sa(t_list **lsta)
{
	void	*temp;

	if (lsta[0] == NULL || lsta[0]->next == NULL)
		return ;
	temp = lsta[0]->content;
	lsta[0]->content = lsta[0]->next->content;
	lsta[0]->next->content = temp;
	ft_printf("sa\n");
}

void	sb(t_list **lstb)
{
	void	*temp;

	if (lstb[0] == NULL || lstb[0]->next == NULL)
		return ;
	temp = lstb[0]->content;
	lstb[0]->content = lstb[0]->next->content;
	lstb[0]->next->content = temp;
	ft_printf("sb\n");
}

void	ss(t_list **lsta, t_list **lstb)
{
	sa(lsta);
	sb(lstb);
	ft_printf("ss\n");
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}