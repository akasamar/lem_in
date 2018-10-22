/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findandclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 03:52:31 by akasamar          #+#    #+#             */
/*   Updated: 2018/06/16 03:52:35 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_backvaluestep(t_info *fn, t_info *axaxa)
{
	ft_makestepnearfinish(fn);
	ft_fillfn(axaxa, 0, 1, axaxa);
}

t_info	*ft_findstart(t_info *lst)
{
	while (lst)
	{
		if (lst->type == 1)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_info	*ft_findfinish(t_info *lst)
{
	while (lst)
	{
		if (lst->type == 2)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int		ft_checkfinish(t_info *lst)
{
	int i;

	i = lst->countedges - 1;
	while (i >= 0)
	{
		if (lst->edges[i--]->type == 2)
			return (1);
	}
	return (0);
}

void	ft_clearfn(t_info *lst)
{
	while (lst)
	{
		if (lst->stepsfn != 999999)
			lst->stepsfn = 0;
		if (lst->steps != 999999)
			lst->steps = 0;
		if (lst->set != 0)
			lst->set = 0;
		if (lst->next2 != NULL)
			lst->next2 = NULL;
		lst = lst->next;
	}
}
