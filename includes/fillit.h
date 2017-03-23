/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:02:43 by mrembusc          #+#    #+#             */
/*   Updated: 2016/12/13 15:00:55 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../lib/libft/includes/libft.h"

typedef struct		s_tris
{
	int				x_0;
	int				y_0;
	int				x_1;
	int				y_1;
	int				x_2;
	int				y_2;
	int				x_3;
	int				y_3;
	char			alpha;
	struct s_tris	*prev;
	struct s_tris	*next;
}					t_tris;

typedef struct		s_stk
{
	int				x;
	int				y;
	int				hash;
}					t_stk;

int					ft_len_map(t_tris *lst);
void				ft_set_map(char ***map, int len);
int					ft_creat_map(char ***map, int len, t_tris *lst);

void				ft_stock_coord(t_tris **lst, char **tab);
void				ft_copy_stock_coor(t_tris **lst, t_stk **stk, char **tab);
t_tris				*ft_split_tetri(char *str);
t_tris				*ft_set_t_tris(t_tris *lst, char alpha);

int					ft_check(char *str);
int					ft_check_tetri(char *str);
int					ft_check_charset(char *str);
int					ft_check_dothash(char *str);
int					ft_check_n(char *str, int i, int *j, int *k);

char				*ft_read(const char *pathname);

int					ft_check_argc(int argc);

int					ft_is_placeable(t_tris *lst, char **tab, int x, int y);
int					ft_insert_piece(t_tris *lst, char ***tab, int x, int y);
void				ft_clean_piece(t_tris *lst, char ***tab, int x, int y);
int					ft_place_tetri(t_tris *lst, char ***map);
void				ft_resolver(t_tris *lst, char ***map);

#endif
