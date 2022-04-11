
#include "push_swap.h"

void resolve5_3(t_list** lst,int size)
{
	if(is_sortedl(lst[0], size))
		return;
	if(size == 1)
		return;
	if(size == 2)
	{
		sa(lst);
		return;
	}

	if(to_int(lst[0]->content) > to_int(lst[0]->next->content) &&
	   to_int(lst[0]->content) >  to_int(lst[0]->next->next->content))
	{
		if(to_int(lst[0]->next->content) > to_int(lst[0]->next->next->content))
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
	else if(to_int(lst[0]->content) > to_int(lst[0]->next->content))
		sa(lst);
	else if(to_int(lst[0]->content) < to_int(lst[0]->next->next->content))
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