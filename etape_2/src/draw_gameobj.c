/*
** draw_gameobj.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 16:25:45 2014 guerot_a
** Last update Sun Mar  9 16:27:33 2014 guerot_a
*/

#include "epikong.h"

static void	draw_mario(t_mario* mario, SDL_Surface* screen)
{
  int	x;
  int	y;

  x = mario->pos_x;
  y = mario->pos_y;
  if (mario->is_die)
    {
      draw_sprite_aligned(get_sprite_by_str("Death"), x, y, screen);
      return;
    }
  if (mario->jumping != NOT_JUMPING)
    {
      if (mario->direction_jump == DIR_LEFT ||
	  mario->direction == DIR_LEFT)
	draw_sprite_aligned(get_sprite_by_str("MarioJump"), x, y, screen);
      else if (mario->direction_jump == DIR_RIGHT ||
	       mario->direction == DIR_RIGHT)
        draw_sprite_aligned(get_sprite_by_str("MarioJumpBack"),
			    x, y, screen);
      return;
    }
  if (mario->direction == DIR_LEFT)
    draw_sprite_aligned(get_sprite_by_str("Mario"), x, y, screen);
  else if (mario->direction == DIR_RIGHT)
    draw_sprite_aligned(get_sprite_by_str("MarioBack"), x, y, screen);
}

static void	draw_monster(t_monster* monster, SDL_Surface *screen)
{
  if (monster->type == MONSTER2)
    {
      if (monster->direction == DIR_RIGHT)
	draw_sprite_aligned(get_sprite_by_str("MonsterBack2"),
			    monster->pos_x, monster->pos_y,
			    screen);
      else if (monster->direction == DIR_LEFT)
	draw_sprite_aligned(get_sprite_by_str("Monster2"),
			    monster->pos_x, monster->pos_y,
			    screen);
    }
  else
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
}

static void	draw_projectile(t_projectile* projectile, SDL_Surface* screen)
{
   draw_sprite_aligned(get_sprite_by_str("Projectile"),
		       projectile->pos_x, projectile->pos_y,
		       screen);
}

void	draw_gameobject(t_objlist* list, SDL_Surface* screen)
{
  t_listit	it;

  it = list_begin(list->monster_list);
  while (it != list_end(list->monster_list))
    {
      draw_monster(it->data, screen);
      it_incr(it);
    }
  it = list_begin(list->projectile_list);
  while (it != list_end(list->projectile_list))
    {
      draw_projectile(it->data, screen);
      it_incr(it);
    }
  draw_mario(&list->player, screen);
}
