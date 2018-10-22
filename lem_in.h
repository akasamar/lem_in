/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 04:31:20 by akasamar          #+#    #+#             */
/*   Updated: 2018/06/16 04:31:41 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"

typedef struct		s_info
{
	char			*name;
	int				x;
	int				y;
	int				steps;
	int				stepsfn;
	int				type;
	int				countedges;
	int				set;
	int				trigger;
	int				length;
	int				ant_here;
	int				ant_name;
	struct s_info	**edges;
	struct s_info	*next;
	struct s_info	*next2;
}					t_info;

typedef struct		s_other
{
	int				ants;
	int				antname;
	int				finishants;
	int				existant;
	int				islink;
}					t_other;

t_info				*ft_create(char **mas, t_info *new, int type, t_other *l);
char				**ft_validroom(char *s);
void				ft_errorlist(int n);
int					ft_valid_ant(char *s);
t_other				ft_fillstruct(void);
void				ft_linkvalid(char *s);
void				ft_connectlinks(t_info *lst, char *s, int i);
void				ft_checkroom(t_info **lst, int i, t_info *fst, t_other *xa);
void				ft_recursion(t_info *lst, t_other *xa, int i);
void				ft_backvaluestep(t_info *fn, t_info *axaxa);
t_info				*ft_findstart(t_info *lst);
t_info				*ft_findfinish(t_info *lst);
int					ft_checkfinish(t_info *lst);
void				ft_clearfn(t_info *lst);
void				ft_makestepnearfinish(t_info *lst);
void				myprintf(int ant_name, char *s, int i);
void				ft_fillsteps(t_info *lst, int stop, int steps, t_info *fst);
void				ft_sort(t_info *lst);
void				ft_putfinish(t_info *lst, t_info *finish);
void				ft_writelength(t_info *lst);
void				ft_existfinorsrt(t_info *lst);
void				print_rooms(t_info **dbl, t_info *lst, int len);
void				ft_makestepnearstart(t_info *lst);
void				ft_makestepnearfinish(t_info *lst);
void				ft_fillsteps(t_info *lst, int stop, int steps, t_info *fst);
void				ft_fillfn(t_info *lst, int stop, int steps, t_info *fst);
int					ft_makeway(t_info *lst, t_info *fn, int i, t_info *axaxa);
void				ft_enter_ants(int k, t_info **dbl, t_other *xa, int sants);

#endif
