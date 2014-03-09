/*
** boss_jump.c for  in /home/guerot_a/depots/T2Rush1/etape_4
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 20:49:27 2014 guerot_a
** Last update Sun Mar  9 20:50:15 2014 guerot_a
*/

#include "epikong.h"

void	boss_jump(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y;
  if ((!IS_WALL(map->data[y + 1][x]) && map->data[y + 1][x] != 's'
      && map->data[y][x] != 's') || objlist->boss.is_die)
    return;
  objlist->boss.jumping = JUMP_STEP1;
  objlist->boss.direction_jump = DIR_NONE;
  objlist->cyclecount++;
}

void	boss_jump_right(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y;
  if ((!IS_WALL(map->data[y + 1][x]) && map->data[y + 1][x] != 's'
      && map->data[y][x] != 's') || objlist->boss.is_die)
    return;
  objlist->boss.jumping = JUMP_STEP1;
  objlist->boss.direction_jump = DIR_RIGHT;
  objlist->cyclecount++;
}

void	boss_jump_left(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y;
  if ((!IS_WALL(map->data[y + 1][x]) && map->data[y + 1][x] != 's'
       && map->data[y][x] != 's') || objlist->boss.is_die)
    return;
  objlist->boss.jumping = JUMP_STEP1;
  objlist->boss.direction_jump = DIR_LEFT;
  objlist->cyclecount++;
}
