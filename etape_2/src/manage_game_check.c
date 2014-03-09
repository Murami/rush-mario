/*
** manage_game_check.c for  in /home/sadows_g/rendu/T2Rush1/etape_2
**
** Made by SADOWSKI Geoffroy
** Login   <sadows_g@epitech.net>
**
** Started on  Sat Mar  8 21:40:59 2014 SADOWSKI Geoffroy
** Last update Sun Mar  9 01:06:05 2014 guerot_a
*/

#include "epikong.h"

#define DIR_DELAY	1000

void	manage_game_check_xy(t_map *map, t_objlist *objlist, int x, int y)
{
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
  check_monster_collide(objlist);
}

void	mario_die(t_objlist* objlist)
{
  objlist->player.lasttime_die = SDL_GetTicks();
  objlist->player.is_die = 1;
}
