/*
** draw.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 13:52:17 2014 guerot_a
** Last update Sun Mar  9 02:59:43 2014 SADOWSKI Geoffroy
*/

#include "epikong.h"

static void	draw_sprite_aligned(SDL_Surface* sprite, int x_case,
			    int y_case, SDL_Surface* screen)
{
  SDL_Rect	rect;

  rect.x = CASE_SIZE * x_case;
  rect.y = CASE_SIZE * y_case;
  SDL_BlitSurface(sprite, NULL, screen, &rect);
}

void	draw_map(t_map* map, SDL_Surface* screen)
{
  unsigned int	x;
  unsigned int	y;

  y = 0;
  while (y < map->height)
    {
      x = 0;
      while (x < map->width)
	{
	  draw_sprite_aligned(get_sprite_by_char(map->data[y][x]), x, y, screen);
	  x++;
	}
      y++;
    }
}

void	draw_mario(t_mario* mario, SDL_Surface* screen)
{
  if (mario->is_die)
    {
      draw_sprite_aligned(get_sprite_by_str("Death"),
			  mario->pos_x, mario->pos_y, screen);
      return;
    }
  if (mario->jumping != NOT_JUMPING)
    {
      if (mario->direction_jump == DIR_LEFT ||
	  mario->direction == DIR_LEFT)
	draw_sprite_aligned(get_sprite_by_str("MarioJump"),
			    mario->pos_x, mario->pos_y, screen);
      else if (mario->direction_jump == DIR_RIGHT ||
	       mario->direction == DIR_RIGHT)
        draw_sprite_aligned(get_sprite_by_str("MarioJumpBack"),
                            mario->pos_x, mario->pos_y, screen);
    }
  else
    {
      if (mario->direction == DIR_LEFT)
	draw_sprite_aligned(get_sprite_by_str("Mario"),
			    mario->pos_x, mario->pos_y, screen);
      else if (mario->direction == DIR_RIGHT)
        draw_sprite_aligned(get_sprite_by_str("MarioBack"),
                            mario->pos_x, mario->pos_y, screen);
    }
}

void	draw_monster(t_monster* monster, SDL_Surface *screen)
{
  if (monster->direction == DIR_RIGHT)
    draw_sprite_aligned(get_sprite_by_str("Monster"),
			monster->pos_x, monster->pos_y,
			screen);
  else if (monster->direction == DIR_LEFT)
    draw_sprite_aligned(get_sprite_by_str("MonsterBack"),
                        monster->pos_x, monster->pos_y,
                        screen);
}

void	draw_gameobject(t_objlist* list, SDL_Surface* screen)
{
  t_listit	it;

  draw_mario(&list->player, screen);
  it = list_begin(list->monster_list);
  while (it != list_end(list->monster_list))
    {
      draw_monster(it->data, screen);
      it_incr(it);
    }
}
