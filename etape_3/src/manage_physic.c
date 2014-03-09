/*
** manage_physic.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:05:50 2014 guerot_a
** Last update Sun Mar  9 16:33:02 2014 guerot_a
*/

#include "epikong.h"

static void	mario_falling(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;
  int	speed_fall;

  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (objlist->player.speed_fall == 1)
    objlist->player.fall_dist = 0;
  speed_fall = objlist->player.speed_fall;
  if (mario_can_walk(map, x, y) || objlist->player.jumping != NOT_JUMPING)
    return;
  while (!mario_can_walk(map, x, y) && speed_fall)
    {
      manage_game_check_xy(map, objlist, x, ++y - 1);
      speed_fall--;
    }
  objlist->player.fall_dist += objlist->player.speed_fall;
  objlist->player.pos_y = y;
  objlist->player.speed_fall *= objlist->player.speed_fall;
  if (objlist->player.speed_fall == 1)
    objlist->player.speed_fall = 2;
  if (mario_can_walk(map, x, y))
    objlist->player.speed_fall = 1;
  if (objlist->player.fall_dist > 4)
    mario_die(objlist);
}

void	manage_physics(t_map* map, t_objlist* objlist)
{
  Uint32	time;

  time = SDL_GetTicks();
  if (time - objlist->player.lasttime_fall > PERIOD_FALL)
    {
      mario_falling(map, objlist);
      objlist->player.lasttime_fall = time;
    }
  mario_jumping(map, objlist);
}
