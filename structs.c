/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 03:50:10 by akasamar          #+#    #+#             */
/*   Updated: 2018/06/16 03:50:16 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_other		ft_fillstruct(void)
{
	t_other new;

	new.ants = 0;
	new.antname = 0;
	new.finishants = 0;
	new.existant = 0;
	new.islink = 0;
	return (new);
}

static void	ft_checkeoomname(t_info *lst, char *s, char *s2, char *s3)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	while (lst)
	{
		if (!ft_strcmp(lst->name, s))
			count++;
		if ((ft_atoi(s2) == lst->x) && (ft_atoi(s3) == lst->y))
			count2++;
		lst = lst->next;
	}
	free(s);
	free(s2);
	free(s3);
	if (count > 1 || count2 > 1)
		ft_errorlist(8);
}

static void	fill_room(char **mas, t_info *new, int type)
{
	new->name = ft_strdup(mas[0]);
	new->x = ft_atoi(mas[1]);
	new->y = ft_atoi(mas[2]);
	new->steps = 0;
	new->stepsfn = 0;
	new->type = type;
	new->set = 0;
	if (new->type == 1 || new->type == 2)
	{
		new->steps = 999999;
		new->stepsfn = 999999;
	}
	new->next2 = NULL;
	new->countedges = 0;
	new->length = 0;
	new->ant_here = 0;
	new->ant_name = 0;
	new->edges = (t_info **)malloc(sizeof(t_info *) * 200);
	free(mas);
}

t_info		*ft_create(char **mas, t_info *new, int type, t_other *l)
{
	t_info *first;
	t_info *p;

	p = (t_info *)malloc(sizeof(t_info));
	l->islink > 0 ? ft_errorlist(7) : 0;
	if (!new)
	{
		new = p;
		first = new;
		fill_room(mas, new, type);
	}
	else
	{
		first = new;
		while (new->next)
			new = new->next;
		new->next = p;
		new = new->next;
		fill_room(mas, new, type);
	}
	new->next = NULL;
	ft_checkeoomname(first, mas[0], mas[1], mas[2]);
	return (first);
}
