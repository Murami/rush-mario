/*
** load_boss.c for  in /home/guerot_a/depots/T2Rush1/etape_4
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 19:53:46 2014 guerot_a
** Last update Sun Mar  9 19:59:48 2014 guerot_a
*/

#include "epikong.h"

void	load_boss(int x, int y, t_objlist* objlist)
{
  objlist->boss.life = 3;
  objlist->boss.pos_x = x;
  objlist->boss.pos_y = y;
  objlist->boss.equiped = 0;
  objlist->boss.speed_fall = 1;
  objlist->boss.lasttime_fall = 0;
  objlist->boss.lasttime_jump = 0;
  objlist->boss.lasttime_walk = 0;
  objlist->boss.lasttime_die = 0;
  objlist->boss.lasttime_fire = 0;
  objlist->boss.jumping = NOT_JUMPING;
  objlist->boss.direction = DIR_RIGHT;
  objlist->boss.is_die = 0;
  objlist->boss.key = 0;
  objlist->spawn_boss.pos_x = x;
  objlist->spawn_boss.pos_y = y;
}
