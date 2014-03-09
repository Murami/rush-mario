/*
** mario_jump.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 16:35:22 2014 guerot_a
** Last update Sun Mar  9 18:32:48 2014 guerot_a
*/

#include "epikong.h"

void	mario_jump(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if ((!IS_WALL(map->data[y + 1][x]) && map->data[y + 1][x] != 's'
      && map->data[y][x] != 's') || objlist->player.is_die)
    return;
  objlist->player.jumping = JUMP_STEP1;
  objlist->player.direction_jump = DIR_NONE;
  objlist->cyclecount++;
}

void	mario_jump_right(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if ((!IS_WALL(map->data[y + 1][x]) && map->data[y + 1][x] != 's'
      && map->data[y][x] != 's') || objlist->player.is_die)
    return;
  objlist->player.jumping = JUMP_STEP1;
  objlist->player.direction_jump = DIR_RIGHT;
  objlist->cyclecount++;
}

void	mario_jump_left(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if ((!IS_WALL(map->data[y + 1][x]) && map->data[y + 1][x] != 's'
       && map->data[y][x] != 's') || objlist->player.is_die)
    return;
  objlist->player.jumping = JUMP_STEP1;
  objlist->player.direction_jump = DIR_LEFT;
  objlist->cyclecount++;
}
