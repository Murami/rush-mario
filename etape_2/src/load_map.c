/*
** load_map.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 00:02:15 2014 guerot_a
** Last update Sat Mar  8 12:54:35 2014 guerot_a
*/

#include "epikong.h"

static t_list	load_file(char *filename)
{
  FILE*		mapfile;
  char*		str;
  size_t	nread;
  t_list	list;

  list = list_create();
  mapfile = fopen(filename, "r");
  if (mapfile == NULL)
    xabort("error: can't open map given in parameter");
  str = NULL;
  while (getline(&str, &nread, mapfile) != -1)
    {
      if (strlen(str))
	str[strlen(str) - 1] = '\0';
      list_push_back(list, str);
      str = NULL;
    }
  fclose(mapfile);
  return (list);
}

void	load_map(char *filename, t_map* map)
{
  t_list	list;
  t_listit	it;
  int		i;

  list = load_file(filename);
  map->height = list_size(list);
  if (!map->height)
    xabort("error: invalid map");
  map->width = strlen(list->next->data);
  if (!map->width)
    xabort("error: invalid map");
  map->data = xmalloc((map->width + 1) * sizeof(char*));
  it = list_begin(list);
  i = 0;
  while (it != list_end(list))
    {
      map->data[i] = it->data;
      if (strlen(it->data) != map->width)
	xabort("error: invalid map");
      it_incr(it);
      i++;
    }
  list_delete(list);
  verif_map(map);
}
