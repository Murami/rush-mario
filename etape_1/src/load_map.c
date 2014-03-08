/*
** load_map.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 00:02:15 2014 guerot_a
** Last update Sat Mar  8 02:39:22 2014 guerot_a
*/

#include "epikong.h"

char	valid_char[] =
  {
    '.',
    'o',
    'w',
    'k',
    'i',
    's',
    'm',
    '\0'
  };

static void	test_valid_char(char key)
{
  int		i;

  i = 0;
  while (valid_char[i])
    {
      if (valid_char[i] == key)
	return;
      i++;
    }
  xabort("error: invalid map");
}

static void	check_line_wall(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] != 'w')
	xabort("error: invalid map");
      i++;
    }
}

static void	update_verif(char mapkey[3], int mapval[3], char key)
{
  int	i;

  i = 0;
  while (i < 3)
    {
      if (mapkey[i] == key)
	mapval[i]++;
      i++;
    }
}

static void	verif_map(t_map *map)
{
  char		mapkey[3];
  int		mapval[3];
  unsigned int		y;
  unsigned int		x;

  mapkey[0] = 'k';
  mapkey[1] = 'o';
  mapkey[2] = 'i';
  mapval[0] = 0;
  mapval[1] = 0;
  mapval[2] = 0;
  check_line_wall(map->data[0]);
  check_line_wall(map->data[map->height - 1]);
  y = 0;
  while (y < map->height)
    {
      if (map->data[y][0] != 'w' || map->data[y][strlen(map->data[y]) - 1] != 'w')
	xabort("error: invalid map");
      x = 0;
      while (x < map->width)
	{
	  update_verif(mapkey, mapval, map->data[y][x]);
	  test_valid_char(map->data[y][x]);
	  x++;
	}
      y++;
    }
  if (mapval[0] != 1 || mapval[1] != 1 || mapval[2] != 1)
    xabort("error: invalid map");
}

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
