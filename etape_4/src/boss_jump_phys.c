/*
** boss_jump_phys.c for  in /home/guerot_a/depots/T2Rush1/etape_4
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 20:56:26 2014 guerot_a
** Last update Sun Mar  9 20:57:19 2014 guerot_a
*/

#include "epikong.h"

static void	boss_jumping_up(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  if (objlist->boss.jumping > JUMP_STEP2)
    {
      objlist->boss.jumping = NOT_JUMPING;
      return;
    }
  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y;
  if (map->data[y - 1][x] == 'w')
    {
      objlist->boss.jumping = NOT_JUMPING;
      return;
    }
  objlist->boss.pos_y--;
  if (map->data[y - 1][x] == 's')
    objlist->boss.jumping = NOT_JUMPING;
  else
    objlist->boss.jumping++;
}

static void	boss_jumping_right(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  objlist->boss.direction = DIR_RIGHT;
  if (objlist->boss.jumping > JUMP_STEP3)
    {
      objlist->boss.jumping = NOT_JUMPING;
      return;
    }
  if (objlist->boss.jumping == JUMP_STEP1)
    {
      boss_jumping_up(map, objlist);
      return;
    }
  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y;
  if (map->data[y][x + 1] == 'w')
    {
      objlist->boss.jumping = NOT_JUMPING;
      return;
    }
  objlist->boss.pos_x++;
  objlist->boss.jumping = (map->data[y][x + 1] == 's') ?
    NOT_JUMPING : objlist->boss.jumping + 1;
}

static void	boss_jumping_left(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  objlist->boss.direction = DIR_LEFT;
  if (objlist->boss.jumping > JUMP_STEP3)
    {
      objlist->boss.jumping = NOT_JUMPING;
      return;
    }
  if (objlist->boss.jumping == JUMP_STEP1)
    {
      boss_jumping_up(map, objlist);
      return;
    }
  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y;
  if (map->data[y][x - 1] == 'w')
    {
      objlist->boss.jumping = NOT_JUMPING;
      return;
    }
  objlist->boss.pos_x--;
  objlist->boss.jumping = (map->data[y][x - 1] == 's') ?
    NOT_JUMPING : objlist->boss.jumping + 1;
}

void	boss_jumping(t_map* map, t_objlist* objlist)
{
  Uint32	currtime;

  if (objlist->boss.jumping == NOT_JUMPING)
    return;
  currtime = SDL_GetTicks();
  if (currtime - objlist->boss.lasttime_jump < PERIOD_JUMP)
    return;
  objlist->boss.lasttime_jump = currtime;
  if (objlist->boss.direction_jump == DIR_LEFT)
    boss_jumping_left(map, objlist);
  else if (objlist->boss.direction_jump == DIR_RIGHT)
    boss_jumping_right(map, objlist);
  else
    boss_jumping_up(map, objlist);
}
