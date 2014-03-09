/*
** load_gameobject.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 13:15:52 2014 guerot_a
** Last update Sun Mar  9 20:30:50 2014 guerot_a
*/

#include "epikong.h"

const t_pair_char_func	load_funcs[] =
  {
    {'i', &load_mario},
    {'m', &load_monster},
    {'M', &load_monster2},
    {'B', &load_boss},
    {'\0', NULL}
  };

void	load_mario(int x, int y, t_objlist* objlist)
{
  objlist->player.life = 3;
  objlist->player.pos_x = x;
  objlist->player.pos_y = y;
  objlist->player.equiped = 0;
  objlist->player.speed_fall = 1;
  objlist->player.lasttime_fall = 0;
  objlist->player.lasttime_jump = 0;
  objlist->player.lasttime_walk = 0;
  objlist->player.lasttime_die = 0;
  objlist->player.lasttime_fire = 0;
  objlist->player.jumping = NOT_JUMPING;
  objlist->player.direction = DIR_RIGHT;
  objlist->player.is_die = 0;
  objlist->player.key = 0;
  objlist->spawn.pos_x = x;
  objlist->spawn.pos_y = y;
  objlist->cleared = 0;
  objlist->lastiamove = 0;
  objlist->cyclecount = 0;
}

void	load_monster(int x, int y, t_objlist* objlist)
{
  t_monster*	monster;

  monster = xmalloc(sizeof(t_monster));
  monster->pos_x = x;
  monster->pos_y = y;
  monster->type = MONSTER1;
  monster->direction = DIR_RIGHT;
  list_push_back(objlist->monster_list, monster);
}

void	load_monster2(int x, int y, t_objlist* objlist)
{
  t_monster*	monster;

  monster = xmalloc(sizeof(t_monster));
  monster->pos_x = x;
  monster->pos_y = y;
  monster->type = MONSTER2;
  monster->direction = DIR_RIGHT;
  list_push_back(objlist->monster_list, monster);
}

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
  objlist->projectile_list = list_create();
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
