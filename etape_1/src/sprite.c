/*
** sprite.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 22:00:45 2014 guerot_a
** Last update Fri Mar  7 22:07:07 2014 guerot_a
*/

#include "epikong.h"

SDL_Image*	get_sprite(uint32_t key, t_spritecollection collection)
{
  int		i;

  if (collection == NULL)
    return (NULL);
  i = 0;
  while (collection[i])
    {
      if (collection[i].key == key)
	return (collection[i].image);
      i++;
    }
  return (NULL);
}
