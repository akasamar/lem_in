/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeway_n_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 03:51:26 by akasamar          #+#    #+#             */
/*   Updated: 2018/06/16 03:51:27 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		myprintf(int ant_name, char *s, int i)
{
	if (i == 1)
	{
		ft_putchar('L');
		ft_putnbr(ant_name);
		ft_putchar('-');
		ft_putstr(s);
		ft_putchar(' ');
	}
	if (i == 2)
	{
		ft_putstr(s);
		ft_putstr("->");
	}
}

static void	ft_make4(t_info *lst, int i, int *base_savefn, t_info **save)
{
	if (lst->edges[i]->stepsfn < *base_savefn)
	{
		*save = lst->edges[i];
		*base_savefn = lst->edges[i]->stepsfn;
		lst->next2 = *save;
	}
}

static int	ft_make3(int *check, int *i, t_info *lst, int *base_savefn)
{
	*check = 0;
	*i = lst->countedges;
	*base_savefn = 999999;
	return (1);
}

static int	ft_make2(int *steps, int check, t_info *save, t_info **lst)
{
	(*steps)++;
	if (check == 0)
		return (1);
	save->set = 1;
	*lst = save;
	return (0);
}

int			ft_makeway(t_info *lst, t_info *fn, int i, t_info *axaxa)
{
	int		steps;
	int		check;
	t_info	*save;
	int		base_savefn;

	steps = 1;
	ft_backvaluestep(fn, axaxa);
	while (1 && ft_make3(&check, &i, lst, &base_savefn))
	{
		while (--i >= 0)
		{
			if (ft_checkfinish(lst) == 1 && (((check = 0) || 1)))
				return (1);
			if (lst->edges[i] == lst && ((i-- || 1)))
				continue ;
			if (lst->edges[i]->set == 0 && lst->edges[i]->steps == steps + 1)
			{
				ft_make4(lst, i, &base_savefn, &save);
				check = 1;
			}
		}
		if (ft_make2(&steps, check, save, &lst))
			break ;
	}
	return (0);
}
