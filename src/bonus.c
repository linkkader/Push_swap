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

static void	part(char *cmd,t_list **lst, t_list **lstb)
{
	if (ft_strncmp(cmd, "ra", 2) == 0)
		ra_bonus(lst);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		rb_bonus(lstb);
	else if (ft_strncmp(cmd, "rra", 3) == 0)
		rra_bonus(lst);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		rrb_bonus(lstb);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		rr_bonus(lst, lstb);
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
		rrr_bonus(lst, lstb);
	else if (ft_strncmp(cmd, "pa", 2) == 0)
		pa_bonus(lst, lstb);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		pb_bonus(lst, lstb);
	else if (ft_strncmp(cmd, "sa", 2) == 0)
		sa_bonus(lst);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		sb_bonus(lstb);
	else if (ft_strncmp(cmd, "ss", 2) == 0)
		ss_bonus(lst, lstb);
	else
		ft_putstr_fd("Error", 1);
}

static void	checker(t_list **lst, t_list **lstb)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		part(cmd, lst, lstb);
		free(cmd);
		cmd = get_next_line(0);
	}
}

void	ft_print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putnbr_fd(*(int *)(lst->content), 1);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
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
	if (len != -1)
	{
		checker(&lst, &lstb);
		if (ft_lstsize(lst) == len && ft_lstsize(lstb) == 0 && is_sorted(lst))
			ft_putstr_fd("OK", 1);
		else
			ft_putstr_fd("KO", 1);
	}
	ft_lstclear(&lst, free);
	ft_lstclear(&lstb, free);
	return (0);
}
