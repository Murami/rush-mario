/*
** manage_ia.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:07:11 2014 guerot_a
** Last update Sat Mar  8 18:13:33 2014 genes_k
*/

#include "epikong.h"

int     bot_can_walk(t_map* map, int x, int y)
{
  return (map->data[y + 1][x] == 'w' ||
          map->data[y + 1][x] == 's' ||
          map->data[y][x] == 's');
}

void    bot_left(t_map* map, t_objlist* objlist)
{
  unsigned int  x;
  unsigned int  y;

  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (!bot_can_walk(map, x, y) || map->data[y][x - 1] == 'w')
    return;
  objlist->player.pos_x = x - 1;
}

void    bot_right(t_map* map, t_objlist* objlist)
{
  unsigned int  x;
  unsigned int  y;

  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  if (!bot_can_walk(map, x, y) || map->data[y][x + 1] == 'w')
    return;
  objlist->player.pos_x = x + 1;
}

void	manage_ia(t_map* map, t_objlist* objlist)
{
  /* t_listit      it; */

  /* it = list_begin(objlist->monster_list); */
  /* while (it != list_end(list)) */
  /*   { */

  /*     it_incr(it); */
  /*   } */
  /* return (it); */
}
