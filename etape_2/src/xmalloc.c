/*
** xmalloc.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 23:11:23 2014 guerot_a
** Last update Fri Mar  7 23:13:49 2014 guerot_a
*/

#include "epikong.h"

void*	xmalloc(size_t n)
{
  void*	ptr;

  if ((ptr = malloc(n)) == NULL)
    xabort("error: out of memory");

  return (ptr);
}
