/*
** manage_game_check.c for  in /home/sadows_g/rendu/T2Rush1/etape_2
**
** Made by SADOWSKI Geoffroy
** Login   <sadows_g@epitech.net>
**
** Started on  Sat Mar  8 21:40:59 2014 SADOWSKI Geoffroy
** Last update Sun Mar  9 14:36:06 2014 guerot_a
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

t_gameaction	actions[] =
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

void	manage_projectile(t_map* map, t_objlist* objlist)
{
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
}

void	mario_die(t_objlist* objlist)
{
  objlist->player.lasttime_die = SDL_GetTicks();
  objlist->player.is_die = 1;
  objlist->player.life--;
}
