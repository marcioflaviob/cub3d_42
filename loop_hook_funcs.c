/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:30:24 by trimize           #+#    #+#             */
/*   Updated: 2024/07/16 18:34:33 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dying_handler(t_cube *cub)
{
	cub->fade_factor -= 0.01;
	if (cub->fade_factor < 0.42)
		cub->fade_factor = 0.42;
	fade_to_black(cub, cub->fade_factor, cub->bits_per_pixel);
	died_handler(cub);
	cub->retry = 1;
}

void	hud_options_helper(t_cube *cub, char *atk_amount, char **tmp)
{
	char	*speed_amount;

	mlx_string_put(cub->con, cub->win, WIDTH / 1.049,
		HEIGHT / 7.5, 0xFFFFFF, atk_amount);
	free(*tmp);
	speed_amount = ft_strdup(" x ");
	*tmp = ft_itoa(cub->player.speed_item_amount);
	speed_amount = ft_strjoin_gnl
		(speed_amount, *tmp);
	mlx_string_put(cub->con, cub->win, WIDTH / 1.049,
		HEIGHT / 5, 0xFFFFFF, speed_amount);
	draw_xpm_animation(19, WIDTH / 2, HEIGHT / 2, cub->txt);
	free(speed_amount);
}

void	hud_options_handler(t_cube *cub)
{
	char	*arrow_amount;
	char	*atk_amount;
	char	*tmp;

	if (cub->option_bool == 1 && cub->player.hp > 0 && !cub->tuto)
		draw_options(cub);
	else
		mlx_mouse_hide(cub->con, cub->win);
	arrow_amount = ft_strdup(" x ");
	tmp = ft_itoa(cub->player.arrows);
	arrow_amount = ft_strjoin_gnl(arrow_amount, tmp);
	free(tmp);
	mlx_string_put(cub->con, cub->win, WIDTH / 1.049,
		HEIGHT / 16, 0xFFFFFF, arrow_amount);
	atk_amount = ft_strdup(" x ");
	tmp = ft_itoa(cub->player.atk_item_amount);
	atk_amount = ft_strjoin_gnl
		(atk_amount, tmp);
	hud_options_helper(cub, atk_amount, &tmp);
	(free(tmp), free(atk_amount), free(arrow_amount));
}

void	bg_true(t_cube *cub)
{
	bg_handler(cub);
	draw_xpm_animation(0, WIDTH / 10, HEIGHT / 25, cub->main_menu_assets);
	start_handler(cub);
	if (cub->retry)
	{
		start_keys(cub);
		map_parsing(cub);
		fill_player(cub);
		cub->dropped_index = 0;
	}
}

void	put_enemies(t_cube *cub)
{
	int	idx;

	idx = 0;
	while (idx < cub->enemy_counter)
	{
		if (cub->all_enemies[idx].type == 'n')
			enemy_handler(cub, &cub->all_enemies[idx], cub->nightborne);
		else if (cub->all_enemies[idx].type == 'c')
			enemy_handler(cub, &cub->all_enemies[idx], cub->cute_wolf);
		else if (cub->all_enemies[idx].type == 'p')
			enemy_handler(cub, &cub->all_enemies[idx], cub->plague_doctor);
		else if (cub->all_enemies[idx].type == 'v')
			enemy_handler(cub, &cub->all_enemies[idx], cub->s_warrior);
		else if (cub->all_enemies[idx].type == 's')
			enemy_handler(cub, &cub->all_enemies[idx], cub->skeleton);
		else if (cub->all_enemies[idx].type == 'w')
			enemy_handler(cub, &cub->all_enemies[idx], cub->warrior);
		else if (cub->all_enemies[idx].type == 'k')
			enemy_handler(cub, &cub->all_enemies[idx], cub->skullwolf);
		idx++;
	}
}
