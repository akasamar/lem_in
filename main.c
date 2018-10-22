/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 03:51:55 by akasamar          #+#    #+#             */
/*   Updated: 2018/06/16 03:51:59 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_recursion(t_info *lst, t_other *xa, int i)
{
	t_info	**dbl;
	int		k;

	i = ft_findstart(lst)->countedges - 1;
	k = 0;
	dbl = (t_info **)malloc(sizeof(t_info *) * (i + 2));
	ft_sort(lst);
	while (i >= 0)
	{
		ft_findstart(lst)->edges[i]->set = 1;
		if (ft_makeway(ft_findstart(lst)->edges[i], \
			ft_findfinish(lst), 0, lst) \
			|| ft_findstart(lst)->edges[i]->type == 2)
		{
			dbl[k] = ft_findstart(lst)->edges[i];
			ft_putfinish(dbl[k], ft_findfinish(lst));
			ft_writelength(dbl[k++]);
		}
		i--;
	}
	dbl[k] = NULL;
	print_rooms(dbl, lst, k);
	ft_enter_ants(k, dbl, xa, xa->ants);
	free(dbl);
}

int			ft_checkdiez(char *s, t_other *lst, int c)
{
	if (!ft_strcmp(s, "##start") || !ft_strcmp(s, "##end"))
		return (0);
	if (ft_strlen(s) > 1 && s[0] == '#' && s[1] == '#' && ((c = 1) || 1))
		;
	if (ft_strlen(s) && s[0] == '#' && ((c = 1) || 1))
		;
	if (c)
	{
		lst->existant == 1 ? lst->existant = 0 : 0;
		free(s);
		return (c);
	}
	return (c);
}

static void	ft_in_main(char *s, t_info **start, t_other lst)
{
	if (!ft_strcmp(s, "##start"))
	{
		free(s);
		get_next_line(0, &s);
		while (ft_checkdiez(s, &lst, 0))
			get_next_line(0, &s);
		*start = ft_create(ft_validroom(s), *start, 1, &lst);
	}
	else if (!ft_strcmp(s, "##end"))
	{
		free(s);
		get_next_line(0, &s);
		while (ft_checkdiez(s, &lst, 0))
			get_next_line(0, &s);
		*start = ft_create(ft_validroom(s), *start, 2, &lst);
	}
	else if (ft_strchr(s, '-') && ++lst.islink)
	{
		ft_linkvalid(s);
		ft_connectlinks(*start, s, 0);
		free(s);
	}
	else if (ft_strlen(s) != 0)
		*start = ft_create(ft_validroom(s), *start, 0, &lst);
}

int			main(void)
{
	char	*s;
	t_other lst;
	t_info	*start;

	s = ft_strdup("abc");
	lst = ft_fillstruct();
	start = NULL;
	free(s);
	while (ft_strlen(s) && ++lst.existant && get_next_line(0, &s))
	{
		if (ft_checkdiez(s, &lst, 0))
			continue ;
		if (lst.existant == 1 && ft_valid_ant(s))
		{
			lst.ants = ft_atoi(s);
			free(s);
			continue ;
		}
		ft_in_main(s, &start, lst);
	}
	ft_existfinorsrt(start);
	ft_recursion(start, &lst, 0);
	return (0);
}
