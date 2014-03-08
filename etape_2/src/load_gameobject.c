/*
** load_gameobject.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 13:15:52 2014 guerot_a
** Last update Sat Mar  8 17:09:57 2014 guerot_a
*/

#include "epikong.h"

void	load_mario(int x, int y, t_objlist* objlist)
{
  objlist->player.life = 4;
  objlist->player.pos_x = x;
  objlist->player.pos_y = y;
  objlist->player.equiped = 0;
  objlist->player.speed_fall = 1;
  objlist->player.lasttime_fall = 0;
  objlist->spawn.pos_x = x;
  objlist->spawn.pos_y = y;
}

void	load_monster(int x, int y, t_objlist* objlist)
{
  t_monster*	monster;

  monster = xmalloc(sizeof(t_monster));
  monster->pos_x = x;
  monster->pos_y = y;
  list_push_back(objlist->monster_list, monster);
}

t_pair_char_func	load_funcs[] =
  {
    {'i', &load_mario},
    {'m', &load_monster},
    {'\0', NULL}
  };

int	run_load(char k, int x, int y, t_objlist* objlist)
{
  int	i;

  i = 0;
  while (load_funcs[i].func)
    {
      if (load_funcs[i].key == k)
	{
	  load_funcs[i].func(x, y, objlist);
	  return (1);
	}
      i++;
    }
  return (0);
}

void	load_gameobject(t_map* map, t_objlist* objlist)
{
  unsigned int	y;
  unsigned int	x;

  objlist->monster_list = list_create();
  y = 0;
  while (y < map->height)
    {
      x = 0;
      while (x < map->width)
	{
	  if (run_load(map->data[y][x], x, y, objlist))
	    map->data[y][x] = '.';
	  x++;
	}
      y++;
    }
}