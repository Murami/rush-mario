/*
** manage_game_check.c for  in /home/sadows_g/rendu/T2Rush1/etape_2
**
** Made by SADOWSKI Geoffroy
** Login   <sadows_g@epitech.net>
**
** Started on  Sat Mar  8 21:40:59 2014 SADOWSKI Geoffroy
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Sun Mar  9 15:13:04 2014 genes_k
=======
** Last update Sun Mar  9 15:07:56 2014 guerot_a
>>>>>>> 189fe6b1b468714e8d917f03507ac6f939e24491
=======
** Last update Sun Mar  9 15:10:35 2014 SADOWSKI Geoffroy
>>>>>>> 92fe2d580e83e52b012addb0f2810b4e429bc0cc
=======
** Last update Sun Mar  9 15:46:38 2014 guerot_a
>>>>>>> 1cda97ee16f04547ac1af0813b2653d677e2c983
=======
** Last update Sun Mar  9 16:40:31 2014 guerot_a
>>>>>>> 52f3427d4f8f4bd3da5a85367dfbebe366ba14fd
*/

#include "epikong.h"

const t_gameaction	actions[] =
  {
    {'k', take_key},
    {'l', take_life},
    {'g', take_gun},
    {'o', use_door},
    {'\0', NULL}
  };

void	manage_game_check_xy(t_map *map, t_objlist *objlist, int x, int y)
{
  int	i;

  i = 0;
  while (actions[i].func)
    {
      if (actions[i].key == map->data[y][x])
	actions[i].func(map, objlist, x, y);
      i++;
    }
}

void	check_monster_collide(t_objlist* objlist)
{
  t_listit	it;

  it = list_begin(objlist->monster_list);
  while (it != list_end(objlist->monster_list))
    {
      if (((t_monster*)it->data)->pos_x == objlist->player.pos_x &&
	  ((t_monster*)it->data)->pos_y == objlist->player.pos_y)
	{
	  mario_die(objlist);
	  return;
	}
      it_incr(it);
    }
}

void	manage_game_check(t_map *map, t_objlist *objlist)
{
  Uint32	currtime;
  int		x;
  int		y;

  x = objlist->player.pos_x;
  y = objlist->player.pos_y;
  manage_game_check_xy(map, objlist, x, y);
  currtime = SDL_GetTicks();
  if (currtime - objlist->player.lasttime_die > 1000 && objlist->player.is_die)
    {
      objlist->player.pos_x = objlist->spawn.pos_x;
      objlist->player.pos_y = objlist->spawn.pos_y;
      objlist->player.is_die = 0;
    }
  if (!objlist->player.is_die)
    check_monster_collide(objlist);
  manage_projectile(map, objlist);
}
