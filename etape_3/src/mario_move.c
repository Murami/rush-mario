/*
** mario_move.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 16:36:04 2014 guerot_a
** Last update Sun Mar  9 16:36:28 2014 guerot_a
*/

#include "epikong.h"

void	mario_left(t_map* map, t_objlist* objlist)
{
  unsigned int	x;
  unsigned int	y;

  if (!mario_manage_walk_time(objlist) || objlist->player.is_die)
    return;
  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (!mario_can_walk(map, x, y) || map->data[y][x - 1] == 'w' ||
      map->data[y][x - 1] == '4' || map->data[y][x - 1] == '5')
    return;
  objlist->player.pos_x = x - 1;
  objlist->player.direction = DIR_LEFT;
}

void	mario_right(t_map* map, t_objlist* objlist)
{
  unsigned int	x;
  unsigned int	y;

  if (!mario_manage_walk_time(objlist) || objlist->player.is_die)
    return;
  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (!mario_can_walk(map, x, y) || map->data[y][x + 1] == 'w' ||
      map->data[y][x - 1] == '4' || map->data[y][x - 1] == '5')
    return;
  objlist->player.pos_x = x + 1;
  objlist->player.direction = DIR_RIGHT;
}

void	mario_up(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  if (!mario_manage_walk_time(objlist) || objlist->player.is_die)
    return;
  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (map->data[y][x] != 's' || map->data[y- 1][x] == 'w' ||
      map->data[y- 1][x] == '2')
    return;
  objlist->player.pos_y = y - 1;
}

void	mario_down(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  if (!mario_manage_walk_time(objlist) || objlist->player.is_die)
    return;
  x = objlist->player.pos_x;
  y = objlist->player.pos_y + 1;
  if (map->data[y][x] != 's')
    return;
  objlist->player.pos_y = y;
}
