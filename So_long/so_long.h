/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:27:25 by dpadrini          #+#    #+#             */
/*   Updated: 2022/06/20 13:27:02 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include <mlx.h>

typedef struct s_images {
	void	*img_wall;
	void	*terrain_a;
	void	*terrain_b;
	void	*current_empty;
	void	*player;
	void	*enemy;
	void	*img_collectable;
	int		img_width;
	int		img_height;
}	t_images;

typedef struct s_game {
	char		**matrix;
	int			width;
	int			height;
	void		*mlx;
	void		*victory;
	int			c;
	int			p;
	int			e;
	int			move_count;
	int			x_player;
	int			y_player;
	t_images	images;
}	t_game;

int			sl_hooks(int key, t_game *map);
int			sl_exit(char *str);
void		end_game(t_game *map);
int			sl_check_map(t_game *map);
int			main(int argc, char **argv);
void		sl_free_matrix(t_game *map);
void		sl_fill_map (t_game map, int y, int x);
void		sl_open_images(t_game *map);
void		sl_print_map(t_game *map);
void		sl_struct_allocation(t_game *map);
static void	sl_strcpy(char *matrix, const char *str);
void		sl_matrix(char *selected_map, t_game *map);
void		sl_struct_allocation(t_game *map);
void		sl_errors(char *m);
void		sl_err_alignement(int fd, int width);
int			sl_check_char(t_game *map);
int			sl_check_perimeter_y(t_game *map);
int			sl_check_perimeter_x(t_game *map);
int			sl_check_values(t_game map, int x, int y);
int			sl_check_inside(t_game *map);
void		sl_move_up(t_game *map);
void		sl_move_down(t_game *map);
void		sl_move_left(t_game *map);
void		sl_move_right(t_game *map);

#endif