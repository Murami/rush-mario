/*
** manage_game_check.c for  in /home/sadows_g/rendu/T2Rush1/etape_2
**
** Made by SADOWSKI Geoffroy
** Login   <sadows_g@epitech.net>
**
** Started on  Sat Mar  8 21:40:59 2014 SADOWSKI Geoffroy
** Last update Sun Mar  9 00:05:24 2014 guerot_a
*/

#include "epikong.h"

void	manage_game_check(t_map *map, t_objlist *objlist)
{
  int	x;
  int	y;

  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (map->data[y][x] == 'k')
    {
      objlist->player.key = 1;
      map->data[y][x] = '.';
    }
  if (map->data[y][x] == 'o' && objlist->player.key == 1)
    {
      printf("Niveau Terminé\n");
      exit (1);
    }
}
