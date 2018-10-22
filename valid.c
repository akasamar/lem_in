/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 03:49:43 by akasamar          #+#    #+#             */
/*   Updated: 2018/06/16 03:49:45 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_errorlist(int n)
{
	if (n == 1)
		ft_putstr("[Error]:Some room has invalid parameters!\n");
	if (n == 2)
		ft_putstr("[Error]:Have been input invalid coords!\n");
	if (n == 3)
		ft_putstr("[Error]:No ants or invalid input them number!!\n");
	if (n == 4)
		ft_putstr("[Error]:Start and Finish rooms didn't bind!\n");
	if (n == 5)
		ft_putstr("[Error]:Incorrect link!\n");
	if (n == 6)
		ft_putstr("[Error]:You can't create link with not existing room!!\n");
	if (n == 7)
		ft_putstr("[Error]:You can't create room after links!!\n");
	if (n == 8)
		ft_putstr("[Error]:Same names or coords were detected!\n");
	if (n == 9)
		ft_putstr("[Error]:Start or Finish point can't be created twice!\n");
	if (n == 10)
		ft_putstr("[Error]:Start or Finish point have not created!\n");
	if (n == 11)
		ft_putstr("[Warning]:Double link with the same rooms was detected!!\n");
	n != 11 ? exit(1) : 0;
}

void			ft_linkvalid(char *s)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] == '-')
			count++;
	if (s[0] == '-' || s[ft_strlen(s) - 1] == '-' || count != 1)
	{
		free(s);
		ft_errorlist(5);
	}
}

int				ft_valid_ant(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (!(s[i] > 47 && s[i] < 58) || s[0] == 48)
		{
			free(s);
			ft_errorlist(3);
		}
	}
	return (1);
}

static int		ft_validroom2(char *s, int i, char **data)
{
	int check;
	int doublespace;

	check = 0;
	doublespace = 0;
	while (s[++i])
		s[i] != ' ' && s[i + 1] == ' ' ? check++ : 0;
	i = -1;
	while (s[++i])
		s[i] == ' ' && s[i + 1] == ' ' ? doublespace++ : 0;
	i = -1;
	while (data[++i])
		;
	if ((doublespace > 0 || i != 3) || \
		(!(check == 2 && s[0] != ' ') || s[0] == 'L'))
	{
		free(s);
		ft_errorlist(1);
	}
	return (check);
}

char			**ft_validroom(char *s)
{
	int		i;
	int		k;
	char	**data;
	int		check;

	data = ft_strsplit(s, ' ');
	check = ft_validroom2(s, -1, data);
	k = 0;
	while (check--)
	{
		k++;
		i = -1;
		while (data[k][++i])
		{
			if (!(data[k][i] > 47 && data[k][i] < 58) || \
				(data[k][0] == 48 && ft_strlen(data[k]) > 1))
			{
				free(s);
				ft_errorlist(2);
			}
		}
	}
	free(s);
	return (data);
}
