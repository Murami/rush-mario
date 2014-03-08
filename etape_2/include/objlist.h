/*
** objlist.h for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 13:21:49 2014 guerot_a
** Last update Sat Mar  8 16:59:47 2014 guerot_a
*/

#ifndef OBJLIST_H
# define OBJLIST_H

# include "list.h"

/*
** Game objects
*/

# define DIR_NONE	0
# define DIR_RIGHT	1
# define DIR_LEFT	2
# define DIR_DOWN	3
# define DIR_UP		4

typedef struct	s_mario
{
  int		life;
  int		pos_x;
  int		pos_y;
  int		speed_fall;
  int		equiped;
  Uint32	lasttime_fall;
  int		direction;
}		t_mario;

typedef struct	s_spawn
{
  int		pos_x;
  int		pos_y;
}		t_spawn;

typedef struct	s_monster
{
  int		pos_x;
  int		pos_y;
  int		direction;
}		t_monster;

typedef struct	s_objlist
{
  t_list	monster_list;
  t_mario	player;
  t_spawn	spawn;
}		t_objlist;

#endif /* OBJLIST_H */
