/*
** manage_boss.c for  in /home/guerot_a/depots/T2Rush1/etape_4
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 21:09:03 2014 guerot_a
** Last update Sun Mar  9 21:10:03 2014 guerot_a
*/

#include "epikong.h"

void	bosstake_life(t_map* map, t_objlist* objlist, int x, int y)
{
  objlist->boss.life++;
  map->data[y][x] = '.';
}

void	bosstake_gun(t_map* map, t_objlist* objlist, int x, int y)
{
  objlist->boss.equiped = 1;
  map->data[y][x] = '.';
}

void	boss_die(t_objlist* objlist)
{
  objlist->boss.lasttime_die = SDL_GetTicks();
  objlist->boss.is_die = 1;
  objlist->boss.life--;
}
