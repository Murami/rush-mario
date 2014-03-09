/*
** map.h for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 21:50:58 2014 guerot_a
** Last update Sat Mar  8 13:33:32 2014 guerot_a
*/

#ifndef MAP_H
# define MAP_H

# include "dependencies.h"

typedef struct	s_map
{
  uint32_t	height;
  uint32_t	width;
  char**	data;
}		t_map;

#endif /* MAP_H */
