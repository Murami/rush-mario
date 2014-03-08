/*
** manage_physic.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:05:50 2014 guerot_a
** Last update Sat Mar  8 18:46:35 2014 guerot_a
*/

#include "epikong.h"

#define PERIOD_FALL	150
#define PERIOD_JUMP	150

void	mario_falling(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;
  int	speed_fall;

  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  speed_fall = objlist->player.speed_fall;
  if (mario_can_walk(map, x, y) || objlist->player.jumping != NOT_JUMPING)
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
}

void	mario_jumping_up(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  if (objlist->player.jumping > JUMP_STEP2)
    {
      objlist->player.jumping = NOT_JUMPING;
      return;
    }
  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (map->data[y - 1][x] == 'w')
    {
      objlist->player.jumping = NOT_JUMPING;
      return;
    }
  objlist->player.pos_y--;
  if (map->data[y - 1][x] == 's')
    objlist->player.jumping = NOT_JUMPING;
  else
    objlist->player.jumping++;
}

void	mario_jumping_right(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  if (objlist->player.jumping > JUMP_STEP3)
    {
      objlist->player.jumping = NOT_JUMPING;
      return;
    }
  if (objlist->player.jumping == JUMP_STEP1)
    {
      mario_jumping_up(map, objlist);
      return;
    }
  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (map->data[y][x + 1] == 'w')
    {
      objlist->player.jumping = NOT_JUMPING;
      return;
    }
  objlist->player.pos_x++;
  if (map->data[y][x + 1] == 's')
    objlist->player.jumping = NOT_JUMPING;
  else
    objlist->player.jumping++;
}

void	mario_jumping_left(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  if (objlist->player.jumping > JUMP_STEP3)
    {
      objlist->player.jumping = NOT_JUMPING;
      return;
    }
  if (objlist->player.jumping == JUMP_STEP1)
    {
      mario_jumping_up(map, objlist);
      return;
    }
  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (map->data[y][x - 1] == 'w')
    {
      objlist->player.jumping = NOT_JUMPING;
      return;
    }
  objlist->player.pos_x--;
  if (map->data[y][x - 1] == 's')
    objlist->player.jumping = NOT_JUMPING;
  else
    objlist->player.jumping++;
}

void	mario_jumping(t_map* map, t_objlist* objlist)
{
  Uint32	currtime;

  if (objlist->player.jumping == NOT_JUMPING)
    {
      objlist->player.direction = DIR_NONE;
      return;
    }
  currtime = SDL_GetTicks();
  if (currtime - objlist->player.lasttime_jump < PERIOD_JUMP)
    return;
  objlist->player.lasttime_jump = currtime;
  if (objlist->player.direction == DIR_LEFT)
    mario_jumping_left(map, objlist);
  else if (objlist->player.direction == DIR_RIGHT)
    mario_jumping_right(map, objlist);
  else
    mario_jumping_up(map, objlist);
}

void	manage_physics(t_map* map, t_objlist* objlist)
{
  Uint32	time;

  time = SDL_GetTicks();
  if (time - objlist->player.lasttime_fall > PERIOD_FALL)
    {
      mario_falling(map, objlist);
      mario_jumping(map, objlist);
      objlist->player.lasttime_fall = time;
    }
}
