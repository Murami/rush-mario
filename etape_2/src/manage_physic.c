/*
** manage_physic.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:05:50 2014 guerot_a
** Last update Sat Mar  8 17:13:57 2014 guerot_a
*/

#include "epikong.h"

#define PERIOD_FALL	150

void	mario_physics(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;
  int	speed_fall;

  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  speed_fall = objlist->player.speed_fall;
  if (mario_can_walk(map, x, y))
    return;
  while (!mario_can_walk(map, x, y) && speed_fall)
    {
      y++;
      speed_fall--;
    }
  if (mario_can_walk(map, x, y))
    objlist->player.speed_fall = 1;
  objlist->player.pos_y = y;
  objlist->player.speed_fall *= objlist->player.speed_fall;
  if (objlist->player.speed_fall == 1)
    objlist->player.speed_fall = 2;
  objlist->player.direction = DIR_NONE;
}

void	manage_physics(t_map* map, t_objlist* objlist)
{
  Uint32	time;

  time = SDL_GetTicks();
  if (time - objlist->player.lasttime_fall > PERIOD_FALL)
    {
      mario_physics(map, objlist);
      objlist->player.lasttime_fall = time;
    }
}
