/*
** list_modifier.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 23:18:14 2014 guerot_a
** Last update Fri Mar  7 23:32:58 2014 guerot_a
*/

#include "epikong.h"

void	list_pop_front(t_list list)
{
  t_listelm*	elm;

  if (!list_size(list))
    return;
  elm = list->next;
  list->next = elm->next;
  elm->next->prev = list;
  free(elm);
}

void	list_pop_back(t_list list)
{
  t_listelm*	elm;

  if (!list_size(list))
    return;
  elm = list->prev;
  list->prev = elm->prev;
  elm->next->next = list;
  free(elm);
}

void	list_push_front(t_list list, void* data)
{
  t_listelm*	elm;

  elm = xmalloc(sizeof(t_listelm));
  elm->next = list->next;
  elm->prev = list;
  list->next->prev = elm;
  list->next = elm;
  elm->data = data;
}

void	list_push_back(t_list list, void* data)
{
  t_listelm*	elm;

  elm = xmalloc(sizeof(t_listelm));
  elm->prev = list->prev;
  elm->next = list;
  list->prev->next = elm;
  list->prev = elm;
  elm->data = data;
}

void	list_erase(t_listit it)
{
  it->next->prev = it->prev;
  it->prev->next = it->next;
}
