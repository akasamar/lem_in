/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 03:52:12 by akasamar          #+#    #+#             */
/*   Updated: 2018/06/16 03:52:13 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_bindrooms(char *name2, t_info *n1, t_info *n2)
{
	int i;
	int count;

	i = n1->countedges - 1;
	count = 0;
	while (i >= 0)
	{
		if (!ft_strcmp(n1->edges[i--]->name, name2))
			count++;
	}
	free(name2);
	if (count > 0)
	{
		ft_errorlist(11);
		return ;
	}
	n1->edges[n1->countedges++] = n2;
	n2->edges[n2->countedges++] = n1;
}

static t_info	*ft_checklinkerror(char *name, t_info *lst)
{
	while (lst)
	{
		if (!ft_strcmp(name, lst->name))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static int		ft_checkerror2(t_info *ex, t_info *ex2, char *n1, char *n2)
{
	if (ft_strcmp(n1, n2) == 0)
	{
		free(n1);
		free(n2);
		return (1);
	}
	if (ex == NULL || ex2 == NULL)
	{
		free(n1);
		free(n2);
		ft_errorlist(6);
	}
	return (0);
}

void			ft_connectlinks(t_info *lst, char *s, int i)
{
	char	*name1;
	char	*name2;
	t_info	*fst;
	t_info	*exist;
	t_info	*exist2;

	fst = lst;
	exist = NULL;
	exist2 = NULL;
	while (s[++i] != '-')
		;
	name1 = ft_strsub(s, 0, i);
	name2 = ft_strdup(&s[i + 1]);
	exist = ft_checklinkerror(name1, lst);
	exist2 = ft_checklinkerror(name2, lst);
	if (ft_checkerror2(exist, exist2, name1, name2) == 1)
		return ;
	lst = fst;
	free(name1);
	ft_bindrooms(name2, exist, exist2);
}
