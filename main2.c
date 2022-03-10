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
void pop(t_list **lst)
{
	if(lst[0] != NULL)
		lst[0] = lst[0]->next;
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
void ra_or_rra(t_list **lsta)
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
int isRevSorted (t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		if(toInt(lst->content) < toInt(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return 1;
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

int isSortedL (t_list *lst, int limit)
{
	int 	i;

	i = 1;
	if(limit <= 1)
		return 1;
	while (lst != NULL && lst->next != NULL && i++ < limit)
	{
		if(toInt(lst->content) > toInt(lst->next->content))
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


int is_it_min(t_list *lst, int min)
{
	while (lst)
	{
		if (toInt(lst->content) < min)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int is_it_max(t_list *lst, int max)
{
	while (lst)
	{
		if (toInt(lst->content) > max)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void resolve3B(t_list** lst, t_list** lstb);
void resolve3(t_list** lst, t_list** lstb)
{
	int		pivotValue;
	t_list	*temp;

	lstb[0] = NULL;
	pivotValue = toInt(lst[0]->content);
	while (lst[0] != NULL)
	{
		if (toInt(lst[0]->content) < pivotValue)
			pb(lst,lstb);
		else
		{
			if(is_it_min(lst[0], pivotValue))
				break;
			ra(lst);
			if(isSorted(lst[0]))
				break;
		}
	}
	if(lst[0] != NULL && !isSorted(lst[0]))
	{
		if(lstb[0] == NULL)
			ra(lst);
		resolve3(lst, &temp);
	}
	if(lstb[0] != NULL && !isRevSorted(lstb[0]))
		resolve3B(lstb, &temp);
	while (lstb[0] != NULL)
		pa(lst,lstb);
}

void resolve3B(t_list** lst, t_list** lstb)
{
	int		pivotValue;
	t_list	*temp;

	lstb[0] = NULL;
	pivotValue = toInt(lst[0]->content);
	while (lst[0] != NULL)
	{
		if (toInt(lst[0]->content) > pivotValue)
			pb(lst,lstb);
		else
		{
			if(is_it_max(lst[0], pivotValue))
				break;
			if(isRevSorted(lst[0]))
				break;
			ra(lst);
		}
	}
	if(lst[0] != NULL && !isRevSorted(lst[0]))
	{
		if(lstb[0] == NULL)
			ra(lst);
		resolve3B(lst, &temp);
	}
	if(lstb[0] != NULL && !isSorted(lstb[0]))
	{
		resolve3(lstb,&temp);
	}
	while (lstb[0] != NULL)
		pa(lst,lstb);
}

void resolveTest(t_list** lst, t_list** lstb)
{
	t_list *lst3 = NULL;

	sa(lst);
	//ft_print_lst(lst[0]);
	ft_lstadd_back(&lst3, ft_lstnew(newInt(22)));
	pb(lst, lstb);
	pb(lst, lstb);
	pb(lst, lstb);
	//pb(lst, &lst3);
	//pb(lst, &lst3);
	sa(lst);
	pa(lst, lstb);
	pa(lst, lstb);
	pa(lst, lstb);
}


int get2(t_list* lst, int index)
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

void resolve5_3(t_list** lst,int size)
{
	if(isSortedL(lst[0], size))
		return;
	if(size == 1)
		return;
	if(size == 2)
	{
		sa(lst);
		return;
	}

	if(toInt(lst[0]->content) > toInt(lst[0]->next->content) &&
	   toInt(lst[0]->content) >  toInt(lst[0]->next->next->content))
	{
		if(toInt(lst[0]->next->content) > toInt(lst[0]->next->next->content))
		{
			sa(lst);
			ra(lst);
			sa(lst);
			rra(lst);
			sa(lst);
		}
		else
		{
			sa(lst);
			ra(lst);
			sa(lst);
			rra(lst);
		}
	}
	else if(toInt(lst[0]->content) > toInt(lst[0]->next->content))
		sa(lst);
	else if(toInt(lst[0]->content) < toInt(lst[0]->next->next->content))
	{
		ra(lst);
		sa(lst);
		rra(lst);
	}
	else
	{
		ra(lst);
		sa(lst);
		rra(lst);
		sa(lst);
	}
}


int resolve5rev_3(t_list** lst, int size)
{
	if(isRevSortedL(lst[0], 3))
		return (size);
	if(size == 2)
	{
		sb(lst);
		return (2);
	}
	else if(size == 1)
		return (1);
	if(toInt(lst[0]->content) < toInt(lst[0]->next->content) &&
	   toInt(lst[0]->content) <  toInt(lst[0]->next->next->content))
	{
		if(toInt(lst[0]->next->content) < toInt(lst[0]->next->next->content))
		{
			//ft_printf("coucou2\n");
			sb(lst);
			rb(lst);
			sb(lst);
			rrb(lst);
			sb(lst);
		}
		else
		{
			//ft_printf("coucou3\n");
			sb(lst);
			rb(lst);
			sb(lst);
			rrb(lst);
		}
	}
	else if(toInt(lst[0]->content) < toInt(lst[0]->next->content))
	{
		//ft_printf("coucou4\n");
		sb(lst);
	}
	else if(toInt(lst[0]->content) < toInt(lst[0]->next->next->content))
	{
		rb(lst);
		sb(lst);
		rrb(lst);
		sb(lst);
	}
	else
	{
		rb(lst);
		sb(lst);
		rrb(lst);
	}
	return (3);
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

int index_max(t_list* lst)
{
	int     i;
	int     v;
	int     max;

	i = 0;
	v = toInt(lst->content);
	max = 0;
	while (lst)
	{
		if(toInt(lst->content) > v)
		{
			v = toInt(lst->content);
			max = i;
		}
		i++;
		lst = lst->next;
	}
	return (max);
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

void pb_max(t_list** lst, t_list** lstb)
{
	int     index1;
	int 	size;

	size = ft_lstsize(lstb[0]);
	index1 = index_max(lstb[0]);
	if(index1*2 <= size)
		while (index1-- != 0)
		{
			if(index1 == 0)
			{
				//if(lstb[0]->next != NULL && lstb[0]->next->next != NULL && toInt(lstb[0]) > toInt(lstb[0]->next->next->content))
				sb(lstb);
				//else
				//  rb(lstb);
			}
			else
				rb(lstb);
		}
	else
		while (index1++ < size)
			rrb(lstb);
	pa(lst, lstb);
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

void resolve4_all(t_list** lst, t_list** lstb)
{
	if(isSorted(lst[0]))
		return;
	pa_min(lst, lstb);
	while (ft_lstsize(lst[0]) > 3)
		pa_min(lst, lstb);
	resolve4_3(lst,lstb);
	while (lstb[0])
		pa(lst, lstb);
}

int get2_pivot(t_list** lst, int size)
{
	int 	pivot;

	pivot = get2(lst[0], (size/2));
	if (is_it_min(lst[0], pivot))
	{
		pivot = get2(lst[0], (size/2 -1));
	}
	return pivot;
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

int	n_max(t_list* lst, int v,int limit)
{
	int 	i;
	int 	ii;

	i = 0;
	ii = 0;
	while (ii++ < limit)
	{
		if(toInt(lst->content) > v)
		{
			i++;
		}
		lst = lst->next;
	}
	return (i);
}

int	n_max2(t_list* lst, int v, int size)
{
	int 	i;

	i = 0;
	while (lst && size-- > 0)
	{
		if(toInt(lst->content) >= v)
			i++;
		lst = lst->next;
	}
	return (i);
}

int get2_best_pivot(t_list** lst, int size, int* nb)
{
	int 	pivot;
	int 	i;
	int 	temp;
	int 	count;

	i = 0;
	while (i < size)
	{
		temp = get2(lst[0], i);
		count = n_min(lst[0], temp, size);
		pivot = temp;
		if(count == size/2)
		{
			*nb = count;
			break;
		}
		i++;
	}
	return pivot;
}

int get2_best_pivot2(t_list** lst, int size, int* nb)
{
	int 	pivot;
	int 	i;
	int 	temp;
	int 	count;

	i = 0;
	while (i < size)
	{
		temp = get2(lst[0], i);
		count = n_max(lst[0], temp, size);
		pivot = temp;
		if(count == size/2)
		{
			*nb = count;
			break;
		}
		i++;
	}
	return pivot;
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





int	okcheck(t_list** lst, t_list** lsb)
{
	if(lsb[0] == NULL || lst[0] == NULL)
		return (-1);
	if(toInt(lsb[0]->content) < toInt(lst[0]->content) && isSorted(lst[0]) && isRevSorted(lsb[0]))
	{
		while (lsb[0])
			pa(lst, lsb);
		return (1);
	}
	return (0);
}

int resolve5a(t_list** lst, t_list** lstb, int size);

int max(t_list *lst, int limit);


int resolve5b(t_list** lst, t_list** lstb, int size)
{
	int		pivot;
	int     nb;
	int 	r;
	int 	size2;
	int 	size3;

	r = 0;
	size2 = 0;
	size3 = size;
	if(size <= 3)
		resolve5rev_3(lstb, size);
	else
	{
		pivot = get2_best_pivot2(lstb, size, &nb);
		int rr = max(lstb[0], size);
		nb = n_max(lstb[0], pivot, size);
		size = size - nb;
		while (nb > 0)
		{
			if (toInt(lstb[0]->content) > pivot)
			{
				pa(lst,lstb);
				nb--;
				size2++;
			}
			else
			{
				r++;
				rb(lstb);
			}
		}
		if(isRevSorted(lstb[0]))
		{
			r = 0;
			size = 0;
		}
		else
		{
			while (r-- > 0)
				rrb(lstb);
		}
		if(!isRevSortedL(lstb[0], size))
			resolve5b(lst, lstb, size);
		if(okcheck(lst, lstb))
			return (-1);

		if(size2 > 0)
		{
			resolve5a(lst, lstb, size2);
			//ft_printf("sizee  %d  %d\n", COUNT, size2);
			//ft_print_lst(lstb[0]);
			while (lstb[0] && toInt(lstb[0]->content) != rr)
			{
				if(isSorted(lst[0]) && is_it_min(lst[0], toInt(lst[0]->content)) && is_it_max(lstb[0], toInt(lst[0]->content)))
				{
					//break;
					//ft_print_lst(lst[0]);
					//while (1);
				}
				pb(lst, lstb);
			}
		}
	}
	if(okcheck(lst, lstb))
		return (-1);
	return (size3);
}

int max(t_list *lst, int limit)
{
	int		i;
	int 	m;

	m = toInt(lst->content);
	i = 1;
	while (i++ < limit)
	{
		if(toInt(lst->next->content) > m)
			m = toInt(lst->next->content);
		lst = lst->next;
	}
	return (m);
}

int min(t_list *lst, int limit)
{
	int		i;
	int 	m;

	m = toInt(lst->content);
	i = 1;
	while (i++ < limit)
	{
		if(toInt(lst->next->content) < m)
			m = toInt(lst->next->content);
		lst = lst->next;
	}
	return (m);
}

int resolve5a(t_list** lst, t_list** lstb, int size)
{
	int		pivot;
	int     nb;
	int 	r;
	int 	size2;
	int 	size3;

	r = 0;
	size2 = 0;
	size3 = size;
	if(size <= 3)
	{
		resolve5_3(lst, size);
	}
	else
	{
		pivot = get2_best_pivot(lst, size, &nb);
		nb = n_min(lst[0], pivot, size);
		//ft_print_lstL(lst[0],size);
		size = size - nb;
		while (nb > 0)
		{
			if (toInt(lst[0]->content) < pivot)
			{
				pb(lst,lstb);
				nb--;
				size2++;
			}
			else
			{
				r++;
				ra(lst);
			}
		}
		while (r-- > 0)
			rra(lst);
		if(!isSortedL(lst[0], size))
			resolve5a(lst, lstb, size);
		if(size2 != 0)
		{

			r = min(lstb[0], size2);
			//while (1);
			//ft_print_lst(lstb[0]);
			//ft_printf("sizee  %d  r %d size2 %d\n", COUNT, r,size2);
			size2 = resolve5b(lst, lstb, size2);
			//while (1);
		}
		if(okcheck(lst, lstb))
			return (-1);
		while (toInt(lst[0]->content) != r)
			pa(lst, lstb);
		if(okcheck(lst, lstb))
			return (-1);
	}
	return (size3);
}

int resolve5(t_list** lst, t_list** lstb, int size)
{
	int		pivot;
	int     nb;
	int 	size2;

	size2 = 0;
	if(size <= 5)
		sort_min_5(lst, lstb);
	else
	{
		pivot = get2_best_pivot(lst, size, &nb);
		nb = n_min(lst[0], pivot, size);
		size = size - nb;
		while (nb > 0)
		{
			if (toInt(lst[0]->content) < pivot)
			{
				pb(lst,lstb);
				nb--;
				size2++;
			}
			else
			{
				if(isSorted(lst[0]))
					break;
				ra(lst);
				if(isSorted(lst[0]))
					break;
			}
		}
		if(!isSorted(lst[0]))
			resolve5(lst, lstb, ft_lstsize(lst[0]));
		if (ft_lstsize(lst[0]) + ft_lstsize(lstb[0]) == 100) {
			while (lstb[0])
				pb_max(lst, lstb);
			return 1;
		}
		if(size2 != 0)
			size2 = resolve5b(lst, lstb, size2);
		while (size2-- > 0)
			pa(lst, lstb);
	}
	return (0);
}




int	main(int ac, char **av)
{
	t_list *lst = NULL;
	t_list *lstb = NULL;
	int		len;
	len = save_array(ac, &lst,av);



	//ft_printf("%d \n",len);
	//if(len > 0)
	//resolve3(&lst, &lstb);
	resolve5(&lst,&lstb, len);
	//resolve5b(&lstb,&lst, len);
	//ft_print_lst(lst);
	//resolve5rev_3(&lst, len);
	//if(isRevSortedL(lst, len))
	//ft_print_lst(lst);
	//ft_printf("%d\n", len);
	//ft_printf("%d", get2_best_pivot(&lst, len));
	return (0);
}