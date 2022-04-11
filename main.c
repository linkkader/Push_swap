/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:35:15 by acouliba          #+#    #+#             */
/*   Updated: 2022/02/02 21:35:29 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int COUNT = 0;

int *newInt(int i)
{
	int	*a;

	a = malloc(sizeof(int));
	*a = i;
	return (a);
}

int toInt(void *i)
{
	return (*(int *)(i));
}

int index_min(t_list* lst)
{
	int     i;
	int     v;
	int     min;

	i = 0;
	v = toInt(lst->content);
	min = 0;
	while (lst)
	{
		if(toInt(lst->content) < v)
		{
			v = toInt(lst->content);
			min = i;
		}
		i++;
		lst = lst->next;
	}
	return (min);
}


int is_lst_contains(int a, t_list* lst)
{
	while (lst != NULL)
	{
		if(toInt(lst->content) == a)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void ft_print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		ft_printf("  %d  \n",*(int *)(lst->content));
		lst = lst->next;
	}
}

void ft_print_lstL(t_list *lst, int limit)
{
	int 	i;

	i = 0;
	while (i++< limit)
	{
		ft_printf("  %d  \n",*(int *)(lst->content));
		lst = lst->next;
	}
}



void push(t_list **lst, int i)
{
	ft_lstadd_back(lst, ft_lstnew(newInt(i)));
}
void sa(t_list **lsta)
{
	void	*temp;
	COUNT++;
	if(lsta[0] == NULL || lsta[0]->next == NULL)
		return;
	temp = lsta[0]->content;
	lsta[0]->content = lsta[0]->next->content;
	lsta[0]->next->content = temp;
	ft_printf("sa\n");
}
void sb(t_list **lstb)
{
	void	*temp;
	COUNT++;
	if(lstb[0] == NULL || lstb[0]->next == NULL)
		return;
	temp = lstb[0]->content;
	lstb[0]->content = lstb[0]->next->content;
	lstb[0]->next->content = temp;
	ft_printf("sb\n");
}
void ss(t_list **lsta,t_list **lstb)
{
	sa(lsta);
	sb(lstb);
	ft_printf("ss\n");
}
void pa(t_list **lsta,t_list **lstb)
{
	t_list	*temp;
	COUNT++;
	if(lstb[0] == NULL)
		return;
	temp = lstb[0];
	lstb[0] = lstb[0]->next;
	temp->next = lsta[0];
	lsta[0] = temp;
	ft_printf("pa\n");
}
void pb(t_list **lsta,t_list **lstb)
{
	t_list	*temp;
	COUNT++;
	if(lsta[0] == NULL)
		return;
	temp = lsta[0];
	lsta[0] = lsta[0]->next;
	temp->next = lstb[0];
	lstb[0] = temp;
	ft_printf("pb\n");
}
void ra(t_list **lsta)
{
	t_list	*temp;
	COUNT++;
	if(lsta[0] == NULL || lsta[0]->next == NULL)
		return;
	temp = lsta[0];
	lsta[0] = lsta[0]->next;
	temp->next = NULL;
	ft_lstlast(lsta[0])->next = temp;
	ft_printf("ra\n");
}
void rb(t_list **lstb)
{
	t_list	*temp;
	COUNT++;
	if(lstb[0] == NULL && lstb[0]->next != NULL)
		return;
	temp = lstb[0];
	lstb[0] = lstb[0]->next;
	temp->next = NULL;
	ft_lstlast(lstb[0])->next = temp;
	ft_printf("rb\n");
}
void rra(t_list **lsta)
{
	t_list	*temp;
	t_list	*temp2;
	COUNT++;
	if(lsta[0] == NULL || lsta[0]->next == NULL)
		return;
	temp = lsta[0];
	while (lsta[0]->next->next != NULL)
		lsta[0] = lsta[0]->next;
	lsta[0]->next->next = temp;
	temp2 = lsta[0]->next;
	lsta[0]->next = NULL;
	lsta[0] = temp2;
	ft_printf("rra\n");
}
void rrb(t_list **lstb)
{
	t_list	*temp;
	t_list	*temp2;
	COUNT++;
	if(lstb[0] == NULL || lstb[0]->next == NULL)
		return;
	temp = lstb[0];
	while (lstb[0]->next->next != NULL)
		lstb[0] = lstb[0]->next;
	lstb[0]->next->next = temp;
	temp2 = lstb[0]->next;
	lstb[0]->next = NULL;
	lstb[0] = temp2;
	ft_printf("rrb\n");
}
void rr(t_list **lsta, t_list **lstb)
{
	ra(lsta);
	rb(lstb);
}
void rrr(t_list **lsta, t_list **lstb)
{
	rra(lsta);
	rrb(lstb);
}

int isRevSortedL (t_list *lst, int limit)
{
	int 	i;

	i = 1;
	if(limit <= 1)
		return 1;
	while (lst != NULL && lst->next != NULL && i++ < limit)
	{
		if(toInt(lst->content) < toInt(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return 1;
}

int is_alldigit(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		if(i == 0 && (str[i] == '-' || str[i] == '+' ))
		{
			i++;
			continue;
		}
		if(!ft_isdigit(str[i]))
			return 0;
		i++;
	}
	return (1);
}

int print_error()
{
	ft_printf("Error\n");
	return (0);
}

int	save_array_split(t_list** lst, char **av)
{
	int 	i;
	char	**split;
	int 	a;

	split = ft_split(av[1], ' ');
	i = 0;
	while (split[i])
	{
		if(!is_alldigit(split[i]))
		{
			ft_lstclear(lst, free);
			return print_error();
		}
		a = ft_atoi(split[i]);
		if(is_lst_contains(a, lst[0]))
		{
			ft_lstclear(lst, free);
			return (print_error());
		}
		push(lst, a);
		i++;
	}
	return ft_lstsize(lst[0]);
}


int	save_array(int ac, t_list** lst, char **av)
{
	int 	i;
	int 	a;

	i = 1;
	if(ac == 2)
		return (save_array_split(lst, av));
	while (i < ac)
	{
		if(!is_alldigit(av[i]))
		{
			ft_lstclear(lst, free);
			return (print_error());
		}
		a = ft_atoi(av[i]);
		if(is_lst_contains(a, lst[0]))
		{
			ft_lstclear(lst, free);
			return (print_error());
		}
		push(lst, a);
		i++;
	}
	return ft_lstsize(lst[0]);
}

int get_at(t_list* lst, int index)
{
	int     i;

	i = 0;
	while (lst)
	{
		if(i == index)
			return toInt(lst->content);
		lst = lst->next;
		i++;
	}
	return (0);
}

int isSorted (t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		if(toInt(lst->content) > toInt(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return 1;
}

int	n_min(t_list* lst, int v, int limit)
{
	int 	i;
	int 	ii;

	i = 0;
	ii = 0;
	while (ii++ < limit)
	{
		if(toInt(lst->content) < v)
		{
			i++;
		}
		lst = lst->next;
	}
	return (i);
}

int 	get_pivot(t_list** lst, int size)
{
	int 	pivot;
	int 	i;
	int 	temp;
	int 	count;

	i = 0;
	while (i < size)
	{
		temp = get_at(lst[0], i);
		count = n_min(lst[0], temp, size);
		pivot = temp;
		if(count == size/2)
			break;
		i++;
	}
	return pivot;
}


void	resolverB(t_list** lst, t_list** lstB, int size)
{
	int 	pivot;
	int 	nb;
	int		size2;

	pivot = get_pivot(lstB, size);
	nb = n_min(lstB[0], pivot, size) + 1;
	size2 = nb;
	while (nb > 0)
	{
		if (toInt(lst[0]->content) >= pivot)
		{
			pa(lst,lstB);
			nb--;
		}
		else
		{
			rb(lst);
		}
	}
}


void resolve4_3(t_list** lst, t_list** lstb)
{
	if(isSorted(lst[0]))
		return;
	if(toInt(lst[0]->content) > toInt(lst[0]->next->content) &&
	   toInt(lst[0]->content) >  toInt(lst[0]->next->next->content))
	{
		if(toInt(lst[0]->next->content) > toInt(lst[0]->next->next->content))
		{
			sa(lst);
			rra(lst);
		}
		else ra(lst);
	}
	else if(toInt(lst[0]->content) > toInt(lst[0]->next->content))
		sa(lst);
	else if(toInt(lst[0]->content) < toInt(lst[0]->next->next->content))
	{
		sa(lst);
		ra(lst);
	}
	else
		rra(lst);
}

void pa_min(t_list** lst, t_list** lstb)
{
	int     index1;
	int 	size;

	size = ft_lstsize(lst[0]);
	index1 = index_min(lst[0]);
	if(index1*2 <= size)
		while (index1-- != 0)
			ra(lst);
	else
		while (index1++ < size)
			rra(lst);
	pb(lst, lstb);
}

void resolve4_5(t_list** lst, t_list** lstb)
{
	int		i;

	i = 1;
	if(isSorted(lst[0]))
		return;
	pa_min(lst, lstb);
	if(ft_lstsize(lst[0]) != 3)
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

void sort_min_5(t_list** lst, t_list** lstb)
{
	int 	size;

	size = ft_lstsize(lst[0]);
	if(size == 2)
		ra(lst);
	if(size == 3)
		resolve4_3(lst, lstb);
	else
		resolve4_5(lst, lstb);
}

void	resolver_part()
{

}

void	resolver(t_list** lst, t_list** lstB, int size)
{
	int 	pivot;
	int 	nb;
	int		size2;

	if(size <= 5)
		sort_min_5(lst, lstB);
	else
	{
		pivot = get_pivot(lst, size);
		nb = n_min(lst[0], pivot, size);
		size2 = nb;
		size -= nb;
		while (nb > 0)
		{
			if (toInt(lst[0]->content) <= pivot)
			{
				pb(lst,lstB);
				nb--;
			}
			else
				ra(lst);
		}
		if(!isSorted(lst[0]))
			resolver(lst, lstB, size);

	}
}

int	main(int ac, char **av)
{
	t_list *lst = NULL;
	t_list *lstb = NULL;
	int		len;
	len = save_array(ac, &lst,av);

	resolver(&lst, &lstb, len);
	ft_print_lst(lst);
	return (0);
}