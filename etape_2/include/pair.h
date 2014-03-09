/*
** pair.h for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 13:18:25 2014 guerot_a
** Last update Sun Mar  9 13:45:35 2014 guerot_a
*/

#ifndef PAIR_H
# define PAIR_H

# include "objlist.h"

typedef struct	s_pair_char_func
{
  char		key;
  void		(*func)(int, int, t_objlist*);
}		t_pair_char_func;

typedef struct	s_event
{
  SDLKey	key;
  int		active;
  int		pressed;
  int		released;
  void		(*func)(t_map* map, t_objlist* objlist);
}		t_event;

typedef struct	s_gameaction
{
  char		key;
  void		(*func)(t_map* map, t_objlist* objlist, int x, int y);
}		t_gameaction;

#endif /* PAIR_H */
