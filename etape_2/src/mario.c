/*
** mario.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 14:57:21 2014 guerot_a
** Last update Sun Mar  9 17:15:17 2014 genes_k
*/

#include "epikong.h"

int	mario_manage_walk_time(t_objlist* objlist)
{
  Uint32	currtime;

  currtime = SDL_GetTicks();
  if (currtime - objlist->player.lasttime_walk < MARIO_PERIOD_WALK)
    return (0);
  objlist->player.lasttime_walk = currtime;
  return (1);
}

int	mario_can_walk(t_map* map, int x, int y)
{
  return (map->data[y + 1][x] == 'w' ||
	  map->data[y + 1][x] == 's' ||
	  map->data[y + 1][x] == '7' ||
	  map->data[y + 1][x] == 'c' ||
	  map->data[y + 1][x] == 'r' ||
	  map->data[y][x] == 's');
}

void	mario_fire(t_map* map, t_objlist* objlist)
{
  Uint32	currtime;
  t_projectile	*proj;
  int		direction;

  (void) map;
  if (!objlist->player.equiped || objlist->player.is_die)
    return;
  currtime = SDL_GetTicks();
  if (currtime - objlist->player.lasttime_fire < PERIOD_FIRE)
    return;
  objlist->player.lasttime_fire = currtime;
  proj = xmalloc(sizeof(t_projectile));
  direction = objlist->player.direction;
  if (objlist->player.jumping && objlist->player.direction_jump)
    direction = objlist->player.direction_jump;
  proj->pos_x = objlist->player.pos_x
    + ((direction == DIR_RIGHT) ? 1 : -1);
  proj->pos_y = objlist->player.pos_y;
  if (strchr("wcr2457", map->data[proj->pos_y][proj->pos_x]) != NULL)
    return;
  proj->direction = direction;
  proj->lifetime = 4;
  proj->lastrun = SDL_GetTicks();
  list_push_front(objlist->projectile_list, proj);
}
