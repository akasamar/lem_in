/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 03:50:52 by akasamar          #+#    #+#             */
/*   Updated: 2018/06/16 03:50:54 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_sort2(t_info *lst, t_info *finish)
{
	int		i;
	int		k;
	t_info	*pwd;

	k = 0;
	i = lst->countedges - 1;
	finish->stepsfn = 0;
	while (k < i)
	{
		if ((lst->edges[k]->stepsfn < lst->edges[k + 1]->stepsfn))
		{
			pwd = lst->edges[k + 1];
			lst->edges[k + 1] = lst->edges[k];
			lst->edges[k] = pwd;
			k = 0;
			continue ;
		}
		k++;
	}
	finish->stepsfn = 999999;
}

void		ft_sort(t_info *lst)
{
	int i;

	i = ft_findstart(lst)->countedges - 1;
	ft_makestepnearstart(lst);
	ft_fillsteps(lst, 0, 1, lst);
	while (i >= 0)
	{
		ft_findstart(lst)->edges[i]->set = 1;
		ft_makeway(ft_findstart(lst)->edges[i--], \
			ft_findfinish(lst), 0, lst);
	}
	ft_sort2(ft_findstart(lst), ft_findfinish(lst));
	ft_clearfn(lst);
	ft_makestepnearstart(lst);
	ft_fillsteps(lst, 0, 1, lst);
}

void		ft_putfinish(t_info *lst, t_info *finish)
{
	if (lst->type == 2)
		return ;
	while (lst)
	{
		if (lst->next2 == NULL)
		{
			lst->next2 = finish;
			lst->next2->next2 = NULL;
			break ;
		}
		lst = lst->next2;
	}
}

void		ft_writelength(t_info *lst)
{
	t_info *dwt;

	dwt = lst;
	while (lst)
	{
		dwt->length++;
		lst = lst->next2;
	}
}

void		ft_existfinorsrt(t_info *lst)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	while (lst)
	{
		if (lst->type == 1)
			count++;
		if (lst->type == 2)
			count2++;
		lst = lst->next;
	}
	if (count > 1 || count2 > 1)
		ft_errorlist(9);
	if (count != 1 || count2 != 1)
		ft_errorlist(10);
}
