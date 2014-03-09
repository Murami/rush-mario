/*
** objlist.h for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 13:21:49 2014 guerot_a
** Last update Sun Mar  9 15:10:26 2014 SADOWSKI Geoffroy
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
# define NOT_JUMPING	0
# define JUMP_STEP1	1
# define JUMP_STEP2	2
# define JUMP_STEP3	3
# define MONSTER1	1
# define MONSTER2	2

typedef struct	s_mario
{
  int		pos_x;
  int		pos_y;
  int		life;
  int		equiped;
  int		speed_fall;
  int		fall_dist;
  int		direction;
  int		direction_jump;
  int		jumping;
  int		key;
  int		is_die;
  Uint32	lasttime_die;
  Uint32	lasttime_fall;
  Uint32	lasttime_jump;
  Uint32	lasttime_walk;
  Uint32	lasttime_fire;
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
  int		type;
  Uint32	lasttime_walk;
}		t_monster;

typedef struct	s_projectile
{
  int		pos_x;
  int		pos_y;
  int		lifetime;
  Uint32	lastthrown;
  int		direction;
}		t_projectile;

typedef struct	s_objlist
{
  t_list	monster_list;
  t_list	projectile_list;
  t_mario	player;
  t_spawn	spawn;
  int		cleared;
}		t_objlist;

#endif /* OBJLIST_H */
