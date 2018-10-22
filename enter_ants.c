/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 03:52:41 by akasamar          #+#    #+#             */
/*   Updated: 2018/06/16 03:52:45 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_movements2(t_info **prev, t_info **xz)
{
	*prev = NULL;
	*xz = NULL;
}

static void	ft_moveants(int k, int i, t_info **dbl, t_other *xa)
{
	t_info *fst;
	t_info *prev;
	t_info *xz;

	while (i < k)
	{
		fst = dbl[i];
		ft_movements2(&prev, &xz);
		while (dbl[i] && dbl[i] != xz)
		{
			if (prev != NULL && prev->ant_here == 1 && dbl[i]->ant_here == 0)
			{
				prev->ant_here = 0;
				dbl[i]->ant_name = prev->ant_name;
				dbl[i]->type != 2 ? dbl[i]->ant_here = 1 : xa->finishants++;
				myprintf(dbl[i]->ant_name, dbl[i]->name, 1);
				xz = dbl[i];
				dbl[i] = fst;
				continue ;
			}
			prev = dbl[i];
			dbl[i] = dbl[i]->next2;
		}
		dbl[i++] = fst;
	}
}

static int	ft_nextfinish(t_info *lst, t_other *xa)
{
	int check;

	check = 0;
	if (lst == ft_findfinish(lst))
		while (xa->ants--)
		{
			myprintf(++xa->antname, lst->name, 1);
			xa->finishants++;
			check = 1;
		}
	if (check == 1)
	{
		ft_putstr("\n");
		return (1);
	}
	else
		return (0);
}

void		ft_enter_ants(int k, t_info **dbl, t_other *xa, int sants)
{
	int i;

	if (ft_nextfinish(dbl[0], xa))
		return ;
	ft_moveants(k, 0, dbl, xa);
	i = 0;
	if (xa->ants > 0)
	{
		dbl[i]->ant_here = 1;
		dbl[i]->ant_name = ++xa->antname;
		myprintf(xa->antname, dbl[i]->name, 1);
		xa->ants--;
	}
	while (++i < k)
		if ((dbl[i]->length - dbl[0]->length) < xa->ants)
		{
			dbl[i]->ant_here = 1;
			dbl[i]->ant_name = ++xa->antname;
			myprintf(xa->antname, dbl[i]->name, 1);
			xa->ants--;
		}
	ft_putstr("\n");
	if (xa->finishants != sants)
		ft_enter_ants(k, dbl, xa, sants);
}
