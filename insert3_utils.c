
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

void	ft_print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		ft_printf("  %d  \n",*(int *)(lst->content));
		lst = lst->next;
	}
}