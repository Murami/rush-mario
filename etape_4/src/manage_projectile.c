/*
** manage_projectile.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 16:38:12 2014 guerot_a
** Last update Sun Mar  9 21:39:52 2014 guerot_a
*/

#include "epikong.h"

static void    thrown_left(t_map* map, t_projectile *data)
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

static void    thrown_right(t_map* map, t_projectile *data)
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

static t_listit	projectile_hit_monster(t_objlist* objlist, t_listit projit)
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
      check_hit_players(objlist, proj);
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
