/*
** manage_physic.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:05:50 2014 guerot_a
** Last update Sun Mar  9 00:37:52 2014 guerot_a
*/

#include "epikong.h"

#define PERIOD_FALL	75
#define PERIOD_JUMP	75

void	mario_falling(t_map* map, t_objlist* objlist)
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

  objlist->player.direction = DIR_RIGHT;
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
  objlist->player.jumping = (map->data[y][x + 1] == 's') ?
    NOT_JUMPING : objlist->player.jumping + 1;
}

void	mario_jumping_left(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  objlist->player.direction = DIR_LEFT;
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
  objlist->player.jumping = (map->data[y][x - 1] == 's') ?
    NOT_JUMPING : objlist->player.jumping + 1;
}

void	mario_jumping(t_map* map, t_objlist* objlist)
{
  Uint32	currtime;

  if (objlist->player.jumping == NOT_JUMPING)
    return;
  currtime = SDL_GetTicks();
  if (currtime - objlist->player.lasttime_jump < PERIOD_JUMP)
    return;
  objlist->player.lasttime_jump = currtime;
  if (objlist->player.direction_jump == DIR_LEFT)
    mario_jumping_left(map, objlist);
  else if (objlist->player.direction_jump == DIR_RIGHT)
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
      objlist->player.lasttime_fall = time;
    }
  mario_jumping(map, objlist);
}
