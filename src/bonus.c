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

#include "../includes/push_swap.h"

static void checker(t_list **lst, t_list	**lstb)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		ft_putstr_fd(cmd, 1);
		//if (ft_strncmp(cmd, "ra", 2) == 0)
		//	ra(lst);
		//else if (ft_strncmp(cmd, "rb", 2) == 0)
		//	rb(lstb);
		//else if (ft_strncmp(cmd, "rra", 3) == 0)
		//	rra(lst);
		//else if (ft_strncmp(cmd, "rrb", 3) == 0)
		//	rrb(lstb);
		//else if (ft_strncmp(cmd, "rr", 2) == 0)
		//	rr(lst, lstb);
		//else if (ft_strncmp(cmd, "rrr", 33) == 0)
		//	rrr(lst, lstb);
		//else
		//{
		//	ft_putstr_fd("Error", 1);
		//}
		free(cmd);
		cmd = get_next_line(1);
	}
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*lstb;
	int		len;

	lst = NULL;
	lstb = NULL;
	len = save_array(ac, &lst, av);
	checker(&lst, &lstb);
	if (ft_lstsize(lst) == len && is_sorted(lst))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	ft_lstclear(&lst, free);
	ft_lstclear(&lstb, free);
	system("leaks push_swap");
	return (0);
}
