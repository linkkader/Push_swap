/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouliba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:26:50 by acouliba          #+#    #+#             */
/*   Updated: 2022/04/11 18:26:53 by acouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft.h"

void	sa(t_list **lsta);
void	sb(t_list **lstb);
void	ss(t_list **lsta, t_list **lstb);
void	pa(t_list **lsta, t_list **lstb);
void	pb(t_list **lsta, t_list **lstb);
void	ra_or_rra(t_list **lsta);
void	ra(t_list **lsta);
void	rb(t_list **lstb);
void	rrb(t_list **lstb);
void	rra(t_list **lsta);
void	push(t_list **lst, int i);
void	pop(t_list **lst);
void	rr(t_list **lsta, t_list **lstb);
void	rrr(t_list **lsta, t_list **lstb);


void	sa_bonus(t_list **lsta);
void	sb_bonus(t_list **lstb);
void	ss_bonus(t_list **lsta, t_list **lstb);
void	pa_bonus(t_list **lsta, t_list **lstb);
void	pb_bonus(t_list **lsta, t_list **lstb);
void	ra_bonus(t_list **lsta);
void	rb_bonus(t_list **lstb);
void	rrb_bonus(t_list **lstb);
void	rra_bonus(t_list **lsta);
void	rr_bonus(t_list **lsta, t_list **lstb);
void	rrr_bonus(t_list **lsta, t_list **lstb);
//
int		*new_int(int i);
void	sort_min_5(t_list **lst, t_list **lstb);
int		is_sorted(t_list *lst);
int		to_int(void *i);
int		n_min(t_list *lst, int v, int limit);
int		n_max(t_list *lst, int v, int limit);
int		max(t_list *lst, int limit);
int		get2(t_list *lst, int index);
//
int		resolve5(t_list **lst, t_list **lstb, int size);
int		get2_best_pivot(t_list **lst, int size, int *nb);
int		resolve5b(t_list **lst, t_list **lstb, int size);
int		resolve5rev_3(t_list **lst, int size);
int		is_rev_sortedl(t_list *lst, int limit);
int		is_rev_sorted(t_list *lst);
//
int		resolve5a(t_list **lst, t_list **lstb, int size);
int		is_sortedl(t_list *lst, int limit);
void	resolve5_3(t_list **lst, int size);
//
int		okcheck(t_list **lst, t_list **lsb);
void	pa_min(t_list **lst, t_list **lstb);
void	pb_max(t_list **lst, t_list **lstb);
int		is_sorted(t_list *lst);
int		is_it_min(t_list *lst, int min);
int		is_it_max(t_list *lst, int max);
//
int		save_array(int ac, t_list **lst, char **av);
void	ft_print_lst(t_list *lst);
int		index_min(t_list *lst);
int		min(t_list *lst, int limit);
int		index_max(t_list *lst);

#endif
