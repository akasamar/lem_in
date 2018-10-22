/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <akasamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:17:16 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/05 22:39:40 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		searching_newline(void **newstart, char **line, int i)
{
	int		d;
	char	*s;

	s = *newstart;
	i = -1;
	d = 1;
	while (s[++i] != '\n')
		if (s[i] == '\0')
		{
			d = 0;
			break ;
		}
	*line = ft_strsub(s, 0, i);
	*newstart = ft_strdup(&s[i + d]);
	free(s);
}

static t_list	*check_fd(int fd)
{
	static t_list	*head = NULL;
	t_list			*current;

	current = head;
	while (current != NULL)
	{
		if (fd == (int)current->content_size)
			return (current);
		current = current->next;
	}
	current = ft_lstnew("\0", fd);
	ft_lstadd(&head, current);
	return (current);
}

int				get_next_line(const int fd, char **line)
{
	char	str[BUFF_SIZE + 1];
	int		amount;
	char	*tmp;

	amount = 0;
	if (read(fd, str, 0) < 0 || fd < 0 || line == NULL)
		return (-1);
	while (((amount = read(fd, str, BUFF_SIZE)) > 0))
	{
		str[amount] = '\0';
		tmp = ft_strjoin(check_fd(fd)->content, str);
		free(check_fd(fd)->content);
		check_fd(fd)->content = tmp;
		if (ft_strrchr((const char *)str, '\n') != NULL)
			break ;
	}
	if (!(ft_strlen(check_fd(fd)->content)))
	{
		*line = NULL;
		return (0);
	}
	searching_newline(&(check_fd(fd)->content), &(*line), 0);
	return (1);
}
