/*
** list.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 22:07:38 2014 guerot_a
** Last update Fri Mar  7 23:26:19 2014 guerot_a
*/

#include "epikong.h"

t_list	list_create()
{
  t_list	elm;

  elm = xmalloc(sizeof(t_listelm));
  elm->next = elm;
  elm->prev = elm;
  elm->data = NULL;

  return (elm);
}

void	list_delete(t_list list)
{
  list_clear(list);
  free(list);
}
