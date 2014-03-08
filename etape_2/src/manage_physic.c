/*
** manage_physic.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:05:50 2014 guerot_a
** Last update Sat Mar  8 16:56:18 2014 guerot_a
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
  speed_fall *= speed_fall;
  objlist->player.speed_fall = speed_fall;
  if (speed_fall > 16)
    speed_fall = 16;
  while (!mario_can_walk(map, x, y) && speed_fall)
    {
      y++;
      speed_fall--;
    }
  if (mario_can_walk(map, x, y))
    objlist->player.speed_fall = 1;
  objlist->player.pos_y = y;
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
