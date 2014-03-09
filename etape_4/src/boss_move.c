/*
** boss_move.c for  in /home/guerot_a/depots/T2Rush1/etape_4
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 20:47:02 2014 guerot_a
** Last update Sun Mar  9 20:48:44 2014 guerot_a
*/

#include "epikong.h"

void	boss_left(t_map* map, t_objlist* objlist)
{
  unsigned int	x;
  unsigned int	y;

  if (!boss_manage_walk_time(objlist) || objlist->boss.is_die)
    return;
  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y;
  if (!boss_can_walk(map, x, y) || IS_WALL(map->data[y][x - 1]))
    return;
  objlist->boss.pos_x = x - 1;
  objlist->boss.direction = DIR_LEFT;
  objlist->cyclecount++;
}

void	boss_right(t_map* map, t_objlist* objlist)
{
  unsigned int	x;
  unsigned int	y;

  if (!boss_manage_walk_time(objlist) || objlist->boss.is_die)
    return;
  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y;
  if (!boss_can_walk(map, x, y) || IS_WALL(map->data[y][x + 1]))
    return;
  objlist->boss.pos_x = x + 1;
  objlist->boss.direction = DIR_RIGHT;
  objlist->cyclecount++;
}

void	boss_up(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  if (!boss_manage_walk_time(objlist) || objlist->boss.is_die)
    return;
  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y;
  if (map->data[y][x] != 's' || IS_WALL(map->data[y - 1][x]))
    return;
  objlist->boss.pos_y = y - 1;
  objlist->cyclecount++;
}

void	boss_down(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  if (!boss_manage_walk_time(objlist) || objlist->boss.is_die)
    return;
  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y + 1;
  if (IS_WALL(map->data[y][x]))
    return;
  objlist->boss.pos_y = y;
  objlist->cyclecount++;
}
