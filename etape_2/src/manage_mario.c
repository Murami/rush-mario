/*
** manage_mario.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 16:39:57 2014 guerot_a
** Last update Sun Mar  9 17:49:29 2014 genes_k
*/

#include "epikong.h"

void	use_door(t_map* map, t_objlist* objlist, int x, int y)
{
  (void) map;
  (void) x;
  (void) y;

  objlist->cleared = objlist->player.key;
}

void	take_key(t_map* map, t_objlist* objlist, int x, int y)
{
  objlist->player.key = 1;
  map->data[y][x] = '.';
}

void	take_life(t_map* map, t_objlist* objlist, int x, int y)
{
  objlist->player.life++;
  map->data[y][x] = '.';
}

void	take_gun(t_map* map, t_objlist* objlist, int x, int y)
{
  objlist->player.equiped = 1;
  map->data[y][x] = '.';
}

void	mario_die(t_objlist* objlist)
{
  objlist->player.lasttime_die = SDL_GetTicks();
  objlist->player.is_die = 1;
  objlist->player.life--;
}
