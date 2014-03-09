/*
** sprite.h for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 21:55:43 2014 guerot_a
** Last update Sun Mar  9 18:06:52 2014 guerot_a
*/

#ifndef SPRITE_H
# define SPRITE_H

# include "dependencies.h"

typedef struct	s_spritepair
{
  uint32_t	key_char;
  char*		key_str;
  char*		filename;
  SDL_Surface*	img;
}		t_spritepair;

typedef t_spritepair* t_spritecollection;

extern t_spritepair sprites[];

# endif /* SPRITE_H */
