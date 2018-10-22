/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_n_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 03:51:09 by akasamar          #+#    #+#             */
/*   Updated: 2018/06/16 03:51:15 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_rooms(t_info **dbl, t_info *lst, int len)
{
	int		i;
	t_info	*pzd;

	i = -1;
	if (len == 0)
		ft_errorlist(4);
	ft_putstr("===============WAYS==============\n");
	while (++i < len)
	{
		myprintf(0, ft_findstart(lst)->name, 2);
		pzd = dbl[i];
		while (pzd)
		{
			if (pzd->type == 2)
			{
				ft_putstr(pzd->name);
				ft_putstr("\n");
				break ;
			}
			myprintf(0, pzd->name, 2);
			pzd = pzd->next2;
		}
	}
	ft_putstr("==========ANTS's MOVEMENT=========\n");
}

void	ft_makestepnearstart(t_info *lst)
{
	int i;

	while (lst)
	{
		if (lst->type == 1)
		{
			i = lst->countedges - 1;
			while (i >= 0)
			{
				lst->edges[i]->steps = 1;
				i--;
			}
			break ;
		}
		lst = lst->next;
	}
}

void	ft_makestepnearfinish(t_info *lst)
{
	int i;

	i = lst->countedges - 1;
	while (i >= 0)
	{
		lst->edges[i]->stepsfn = 1;
		i--;
	}
}

void	ft_fillsteps(t_info *lst, int stop, int steps, t_info *fst)
{
	int i;

	while (1 && ((stop = 0) || 1))
	{
		lst = fst;
		while (lst)
		{
			if (lst->type != 1 && lst->type != 2)
			{
				if ((lst->steps == steps) && ((stop = 1) || 1))
				{
					i = lst->countedges;
					while (--i >= 0)
						if (lst->edges[i]->steps == 0)
							lst->edges[i]->steps = steps + 1;
				}
			}
			lst = lst->next;
		}
		if (stop == 0)
			break ;
		steps++;
	}
}

void	ft_fillfn(t_info *lst, int stop, int steps, t_info *fst)
{
	int i;

	while (1 && ((stop = 0) || 1))
	{
		lst = fst;
		while (lst)
		{
			if (lst->type != 1 && lst->type != 2)
			{
				if ((lst->stepsfn == steps) && ((stop = 1) || 1))
				{
					i = lst->countedges;
					while (--i >= 0)
						if (lst->edges[i]->stepsfn == 0)
							lst->edges[i]->stepsfn = steps + 1;
				}
			}
			lst = lst->next;
		}
		if (stop == 0)
			break ;
		steps++;
	}
}
