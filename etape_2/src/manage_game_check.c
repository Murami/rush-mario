/*
** manage_game_check.c for  in /home/sadows_g/rendu/T2Rush1/etape_2
**
** Made by SADOWSKI Geoffroy
** Login   <sadows_g@epitech.net>
**
** Started on  Sat Mar  8 21:40:59 2014 SADOWSKI Geoffroy
** Last update Sun Mar  9 15:46:38 2014 guerot_a
*/

#include "epikong.h"

#define PERIOD_RUN_PROJ 50

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

void    thrown_left(t_map* map, t_projectile *data)
{
  unsigned int  x;
  unsigned int  y;

  x = data->pos_x;
  y = data->pos_y;
  if (map->data[y][x - 1] == 'w' || map->data[y][x - 1] == '4'
      || map->data[y][x - 1] == '5')
    {
      data->lifetime = 0;
      return;
    }
  data->pos_x = x - 1;
}

void    thrown_right(t_map* map, t_projectile *data)
{
  unsigned int  x;
  unsigned int  y;

  x = data->pos_x;
  y = data->pos_y;
  if (map->data[y][x + 1] == 'w' || map->data[y][x + 1] == '4'
      || map->data[y][x + 1] == '5')
    {
      data->lifetime = 0;
      return;
    }
  data->pos_x = x + 1;
}

t_listit	projectile_hit_monster(t_objlist* objlist, t_listit projit)
{
  t_listit	it;
  t_monster*	monster;
  t_projectile*	proj;

  proj = projit->data;
  it = list_begin(objlist->monster_list);
  while (it != list_end(objlist->monster_list))
    {
      monster = it->data;
      it_incr(it);
      if (monster->pos_x == proj->pos_x && monster->pos_y == proj->pos_y)
	{
	  projit = projit->prev;
	  list_erase(projit->next);
	  list_erase(it->prev);
	  return (projit);
	}
    }
  return (projit);
}

t_listit	monster_hit_projectile(t_objlist* objlist, t_listit monster_it)
{
  t_listit	it;
  t_monster*	monster;
  t_projectile*	proj;

  it = list_begin(objlist->projectile_list);
  monster = monster_it->data;
  while (it != list_end(objlist->projectile_list))
    {
      proj = it->data;
      it_incr(it);
      if (monster->pos_x == proj->pos_x && monster->pos_y == proj->pos_y)
	{
	  monster_it = monster_it->prev;
	  list_erase(monster_it->next);
	  list_erase(it->prev);
	  return (monster_it);
	}
    }
  return (monster_it);
}

void	manage_projectile(t_map* map, t_objlist* objlist)
{
  t_list	it;
  t_projectile*	data;
  Uint32	time;

  it = list_begin(objlist->projectile_list);
  while (it != list_end(objlist->projectile_list))
    {
      time = SDL_GetTicks();
      data = it->data;
      if (time - data->lastrun > PERIOD_RUN_PROJ && data->lifetime > 0)
        {
          if (data->direction == DIR_RIGHT)
            thrown_right(map, data);
          else if (data->direction == DIR_LEFT)
            thrown_left(map, data);
          data->lastrun = time;
	  data->lifetime--;
	  it = projectile_hit_monster(objlist, it);
        }
      it_incr(it);
      if (data->lifetime <= 0)
	list_erase(it->prev);
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

void	mario_die(t_objlist* objlist)
{
  objlist->player.lasttime_die = SDL_GetTicks();
  objlist->player.is_die = 1;
  objlist->player.life--;
}
