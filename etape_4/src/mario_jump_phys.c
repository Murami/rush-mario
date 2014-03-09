/*
** mario_jump_phys.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 16:32:04 2014 guerot_a
** Last update Sun Mar  9 20:56:47 2014 guerot_a
*/

#include "epikong.h"

static void	mario_jumping_up(t_map* map, t_objlist* objlist)
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

static void	mario_jumping_right(t_map* map, t_objlist* objlist)
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

static void	mario_jumping_left(t_map* map, t_objlist* objlist)
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
