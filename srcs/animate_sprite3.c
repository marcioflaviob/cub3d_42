/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_sprite3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:32:55 by mbrandao          #+#    #+#             */
/*   Updated: 2024/09/24 20:39:52 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_txt	enemy_animation_atk(t_cube *cub, t_txt *txt, t_enemy *enemy, int dist)
{
	(void) cub;
	update_animation_atk(txt);
	if (txt->current_frame == enemy->atk_max_frame)
	{
		txt->current_frame = 0;
		if (dist < 150)
			enemy->last_attack = 1;
		enemy->attacking_bool = 0;
	}
	else
	{
		enemy->last_attack = 0;
		enemy->attacking_bool = 1;
	}
	return (txt[txt->current_frame]);
}

void	update_animation_hurt(t_txt *txt)
{
	if (txt[txt->current_frame].tmp_delay++ == txt->delay)
	{
		txt[txt->current_frame].tmp_delay = 0;
		txt->current_frame++;
	}
}

t_txt	enemy_animation_hurt(t_cube *cub, t_txt *txt,
	t_enemy *enemy, int max_frame)
{
	(void) cub;
	update_animation_hurt(txt);
	if (txt->current_frame == max_frame)
	{
		txt->current_frame = 0;
		enemy->hurt = 0;
		enemy->attacking_bool = 0;
	}
	return (txt[txt->current_frame]);
}

void	update_animation_death(t_txt *txt)
{
	if (txt[txt->current_frame].tmp_delay++ == txt->delay)
	{
		txt[txt->current_frame].tmp_delay = 0;
		txt->current_frame++;
	}
}

t_txt	enemy_animation_death(t_cube *cub, t_txt *txt,
	t_enemy *enemy, int max_frame)
{
	update_animation_death(txt);
	if (txt->current_frame == max_frame)
	{
		enemy->dead = 1;
		enemy->attacking_bool = 0;
		random_item(cub, &cub->dropped_items[cub->dropped_index]);
		cub->dropped_items[cub->dropped_index].x = enemy->x;
		cub->dropped_items[cub->dropped_index].last_text = 0;
		cub->dropped_items[cub->dropped_index].y = enemy->y;
		cub->dropped_items[cub->dropped_index].dist = 999999;
		if (enemy->type == 'n' || enemy->type == 'p' || enemy->type == 'w')
			cub->items[cub->crown_index].display = 1;
		cub->dropped_index++;
	}
	return (txt[txt->current_frame]);
}
