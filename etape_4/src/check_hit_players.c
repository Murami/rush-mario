/*
** check_hit_players.c for  in /home/guerot_a/depots/T2Rush1/etape_4
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 21:34:58 2014 guerot_a
** Last update Sun Mar  9 21:39:51 2014 guerot_a
*/

#include "epikong.h"

void	check_hit_players(t_objlist* objlist, t_projectile* proj)
{
  if (objlist->player.pos_x == proj->pos_x &&
      objlist->player.pos_y == proj->pos_y)
    mario_die(objlist);
  else if (objlist->boss.pos_x == proj->pos_x &&
	   objlist->boss.pos_y == proj->pos_y)
    boss_die(objlist);
}
