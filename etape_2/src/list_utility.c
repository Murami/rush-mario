/*
** list_utility.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 23:15:09 2014 guerot_a
** Last update Fri Mar  7 23:28:03 2014 guerot_a
*/

#include "epikong.h"

int	list_size(t_list list)
{
  int		i;
  t_listit	it;

  i = 0;
  it = list_begin(list);
  while (it != list_end(list))
    {
      i++;
      it_incr(it);
    }
  return (i);
}

void	list_clear(t_list list)
{
  while (list_size(list))
    list_pop_front(list);
}

t_listit	list_find(t_list list, t_predicate predicate, void* val_cmp)
{
  t_listit	it;

  it = list_begin(list);
  while (it != list_end(list))
    {
      if (predicate(it->data, val_cmp))
	return (it);
      it_incr(it);
    }
  return (it);
}
