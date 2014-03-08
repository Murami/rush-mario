/*
** manage_ia.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 15:07:11 2014 guerot_a
** Last update Sat Mar  8 21:28:50 2014 SADOWSKI Geoffroy
*/

#include "epikong.h"

#define PERIOD_WALK     150

int     bot_can_walk(t_map* map, int x, int y)
{
  return (map->data[y + 1][x] == 'w' ||
          map->data[y + 1][x] == 's' ||
          map->data[y + 1][x] == '7' ||
          map->data[y][x] == 's');
}

void    bot_left(t_map* map, t_monster *data)
{
  unsigned int  x;
  unsigned int  y;

  x = data->pos_x;
  y = data->pos_y;
  if (!bot_can_walk(map, x - 1, y) || map->data[y][x - 1] == 'w' 
      || map->data[y][x - 1] == 'm' || map->data[y][x - 1] == '4'
      || map->data[y][x - 1] == '5')
    {
      data->direction = DIR_RIGHT;
      return;
    }
  data->pos_x = x - 1;
}

void    bot_right(t_map* map, t_monster *data)
{
  unsigned int  x;
  unsigned int  y;


  x = data->pos_x;
  y = data->pos_y;
  if (!bot_can_walk(map, x + 1, y) || map->data[y][x + 1] == 'w'
      || map->data[y][x + 1] == 'm' || map->data[y][x + 1] == '4'
      || map->data[y][x + 1] == '5')
    {
      data->direction = DIR_LEFT;
      return;
    }
  data->pos_x = x + 1;
}

void	manage_ia(t_map* map, t_objlist* objlist)
{
  t_list	it;
  t_monster	*data;
  Uint32	time;

  it = list_begin(objlist->monster_list);
  while (it != list_end(objlist->monster_list))
    {
      time = SDL_GetTicks();
      data = it->data;
      if (time - data->lasttime_walk > PERIOD_WALK)
	{
	  if (data->direction == DIR_RIGHT)
	    bot_right(map,data);
	  else if (data->direction == DIR_LEFT)
	    bot_left(map,data);
	  it_incr(it);
	  data->lasttime_walk = time;
	}
    }
}
