/*
** boss.c for  in /home/guerot_a/depots/T2Rush1/etape_4
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 20:51:52 2014 guerot_a
** Last update Sun Mar  9 20:53:05 2014 guerot_a
*/

#include "epikong.h"

int	boss_manage_walk_time(t_objlist* objlist)
{
  Uint32	currtime;

  currtime = SDL_GetTicks();
  if (currtime - objlist->boss.lasttime_walk < MARIO_PERIOD_WALK)
    return (0);
  objlist->boss.lasttime_walk = currtime;
  return (1);
}

int	boss_can_walk(t_map* map, int x, int y)
{
  return (IS_WALL(map->data[y + 1][x]) ||
	  map->data[y + 1][x] == 's' ||
	  map->data[y][x] == 's');
}

void	boss_fire(t_map* map, t_objlist* objlist)
{
  Uint32	currtime;
  t_projectile	*proj;
  int		direction;

  (void) map;
  if (!objlist->boss.equiped || objlist->boss.is_die)
    return;
  currtime = SDL_GetTicks();
  if (currtime - objlist->boss.lasttime_fire < PERIOD_FIRE)
    return;
  objlist->boss.lasttime_fire = currtime;
  proj = xmalloc(sizeof(t_projectile));
  direction = objlist->boss.direction;
  if (objlist->boss.jumping && objlist->boss.direction_jump)
    direction = objlist->boss.direction_jump;
  proj->pos_x = objlist->boss.pos_x
    + ((direction == DIR_RIGHT) ? 1 : -1);
  proj->pos_y = objlist->boss.pos_y;
  if (IS_WALL(map->data[proj->pos_y][proj->pos_x]) != NULL)
    return;
  proj->direction = direction;
  proj->lifetime = 4;
  proj->lastrun = SDL_GetTicks();
  list_push_front(objlist->projectile_list, proj);
  objlist->cyclecount += 4;
}

void	boss_takekey(t_map* map, t_objlist* objlist)
{
  int	x;
  int	y;

  x = objlist->boss.pos_x;
  y = objlist->boss.pos_y;
  if (map->data[y][x] == 'k')
    {
      objlist->boss.key = 1;
      map->data[y][x] = '.';
    }
}
