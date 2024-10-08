/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 01:01:20 by mbrandao          #+#    #+#             */
/*   Updated: 2024/09/24 20:40:12 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	random_item2(t_cube *cub, t_item *item, int type)
{
	if (type == 2)
	{
		item->txt = &cub->txt[22];
		item->type = 'H';
		item->display = 1;
		item->msg = 0;
		item->last_text = -1;
	}
	else if (type == 3)
	{
		item->txt = &cub->txt[15];
		item->type = 'V';
		item->display = 1;
		item->last_text = 0;
	}
}

void	random_item(t_cube *cub, t_item *item)
{
	int	type;

	type = get_current_time() % 4;
	if (type == 0)
	{
		item->txt = &cub->txt[17];
		item->type = 'Q';
		item->display = 1;
		item->last_text = 0;
	}
	else if (type == 1)
	{
		item->txt = &cub->txt[16];
		item->type = 'A';
		item->display = 1;
		item->last_text = 0;
	}
	else
		random_item2(cub, item, type);
}

void	update_dist(t_cube *cub)
{
	int	i;

	i = -1;
	while (++i < cub->weapon_counter)
		cub->weapons[i].dist = dist((cub->weapons[i].x * TILE_SIZE),
				(cub->weapons[i].y * TILE_SIZE), (cub->player.x * TILE_SIZE),
				(cub->player.y * TILE_SIZE));
	i = -1;
	while (++i < cub->items_counter)
		cub->items[i].dist = dist((cub->items[i].x * TILE_SIZE),
				(cub->items[i].y * TILE_SIZE), (cub->player.x * TILE_SIZE),
				(cub->player.y * TILE_SIZE));
	i = -1;
	while (++i < cub->dropped_index)
		cub->dropped_items[i].dist = dist((cub->dropped_items[i].x * TILE_SIZE),
				(cub->dropped_items[i].y * TILE_SIZE), (cub->player.x
					* TILE_SIZE), (cub->player.y * TILE_SIZE));
}

void	equip_item(t_cube *cub, char type)
{
	if (type == 'Q')
	{
		cub->player.arrows += 3;
	}
	if (type == 'V')
	{
		cub->player.speed += 0.004;
		cub->player.speed_item_amount++;
	}
	if (type == 'A')
	{
		cub->player.atk += 10;
		cub->player.atk_item_amount++;
	}
	if (type == 'H')
	{
		cub->hp_frame->current_frame -= 2;
		cub->player.hp += 25;
	}
}

void	add_weapon_to_slot(t_cube *cub, int index)
{
	int	i;
	int	type;

	i = 0;
	if (cub->weapons[index].type == '|')
		type = 1;
	else if (cub->weapons[index].type == 'C')
		type = 2;
	else if (cub->weapons[index].type == 'O')
		type = 3;
	else if (cub->weapons[index].type == 'G')
		type = 4;
	while (i < 4)
	{
		if (cub->weapons_in_slot[i] == 0)
		{
			cub->weapons_in_slot[i] = type;
			return ;
		}
		i++;
	}
}
