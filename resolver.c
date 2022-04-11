
#include "push_swap.h"
#include "ft_printf.h"

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
		if (count == size/2)
		{
			*nb = count;
			break ;
		}
		i++;
	}
	return (pivot);
}


void	resolve4_3(t_list **lst, t_list **lstb)
{
	if (is_sorted(lst[0]))
		return;
	if (to_int(lst[0]->content) > to_int(lst[0]->next->content)
		&& to_int(lst[0]->content) >  to_int(lst[0]->next->next->content))
	{
		if(to_int(lst[0]->next->content) > to_int(lst[0]->next->next->content))
		{
			sa(lst);
			rra(lst);
		}
		else
			ra(lst);
	}
	else if (to_int(lst[0]->content) > to_int(lst[0]->next->content))
		sa(lst);
	else if(to_int(lst[0]->content) < to_int(lst[0]->next->next->content))
	{
		sa(lst);
		ra(lst);
	}
	else
		rra(lst);
}

void	sort_min_5(t_list **lst, t_list **lstb)
{
	int		size;

	size = ft_lstsize(lst[0]);
	if (size == 2)
		ra(lst);
	if (size == 3)
		resolve4_3(lst, lstb);
	else
		resolve4_5(lst, lstb);
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
	resolve4_3(lst,lstb);
	while (lstb[0] && i > 0)
	{
		i--;
		pa(lst, lstb);
	}
}

int	resolve5_part(t_list **lst, t_list **lstb, int size)
{
	int		size2;
	int		nb;
	int		pivot;

	nb = 0;
	size2 = 0;
	pivot = get2_best_pivot(lst, size, &nb);
	nb = n_min(lst[0], pivot, size);
	size = size - nb;
	while (nb > 0)
	{
		if (to_int(lst[0]->content) < pivot)
		{
			pb(lst, lstb);
			nb--;
			size2++;
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
	return (size2);
}

int	resolve5(t_list **lst, t_list **lstb, int size)
{
	int		size2;

	if (size <= 5)
		sort_min_5(lst, lstb);
	else
	{
		size2 = resolve5_part(lst, lstb, size);
		if (!is_sorted(lst[0]))
			resolve5(lst, lstb, ft_lstsize(lst[0]));
		if (size2 != 0)
			size2 = resolve5b(lst, lstb, size2);
		while (size2-- > 0)
			pa(lst, lstb);
	}
	return (0);
}