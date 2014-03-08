/*
** mario.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 14:57:21 2014 guerot_a
** Last update Sat Mar  8 17:00:59 2014 guerot_a
*/

#include "epikong.h"

int	mario_can_walk(t_map* map, int x, int y)
{
  return (map->data[y + 1][x] == 'w' ||
	  map->data[y + 1][x] == 's' ||
	  map->data[y][x] == 's');
}

void	mario_left(t_map* map, t_objlist* objlist)
{
  unsigned int	x;
  unsigned int	y;

  printf("left\n");
  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (!mario_can_walk(map, x, y) || map->data[y][x - 1] == 'w')
    return;
  objlist->player.pos_x = x - 1;
  objlist->player.direction = DIR_LEFT;
}

void	mario_right(t_map* map, t_objlist* objlist)
{
  unsigned int	x;
  unsigned int	y;

  printf("right\n");
  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (!mario_can_walk(map, x, y) || map->data[y][x + 1] == 'w')
    return;
  objlist->player.pos_x = x + 1;
  objlist->player.direction = DIR_RIGHT;
}

void	mario_up(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  printf("down\n");
  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (map->data[y][x] != 's')
    return;
  objlist->player.pos_y = y - 1;
  objlist->player.direction = DIR_UP;
}

void	mario_down(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  printf("up\n");
  x = objlist->player.pos_x;
  y = objlist->player.pos_y + 1;
  if (map->data[y][x] != 's')
    return;
  objlist->player.pos_y = y;
  objlist->player.direction = DIR_DOWN;
}

/* void	mario_jump() */
/* { */
/* } */

/* void	mario_jump_left() */
/* { */
/* } */

/* void	mario_jump_right() */
/* { */
/* } */