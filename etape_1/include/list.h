/*
** list.h for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Fri Mar  7 22:07:47 2014 guerot_a
** Last update Fri Mar  7 23:33:18 2014 guerot_a
*/

#ifndef LIST_H
# define LIST_H

# define	it_incr(it) (it = it->next)

typedef struct		s_listelm
{
  struct s_listelm*	next;
  struct s_listelm*	prev;
  void*			data;
}			t_listelm;

typedef t_listelm*		t_list;
typedef t_list			t_listit;
typedef int (*t_predicate)(void*, void*);

/*
** list.c
*/

t_list	list_create();
void	list_delete(t_list list);

/*
** list_modifier.c
*/

void	list_pop_front(t_list list);
void	list_pop_back(t_list list);
void	list_push_front(t_list list, void* data);
void	list_push_back(t_list list, void* data);
void	list_erase(t_listit it);

/*
** list_utility.c
*/

int		list_size(t_list list);
void		list_clear(t_list list);
t_listit	list_find(t_list list, t_predicate predicate, void* val_cmp);

/*
** list_iterator.c
*/

t_listit	list_begin(t_list list);
t_listit	list_end(t_list list);


#endif /* LIST_H */
