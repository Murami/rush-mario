/*
** menu.c for  in /home/sadows_g/rendu/T2Rush1/etape_2
** 
** Made by SADOWSKI Geoffroy
** Login   <sadows_g@epitech.net>
** 
** Started on  Sun Mar  9 00:52:42 2014 SADOWSKI Geoffroy
** Last update Sun Mar  9 01:05:53 2014 SADOWSKI Geoffroy
*/

SDL_Surface	*menu_init()
{
  memset(objlist, 0, sizeof(t_objlist));
  SDL_Init(SDL_INIT_VIDEO);
  return (xSDL_SetVideoMode(CASE_SIZE, CASE_SIZE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF));
}

char	*menu()
{
  SDL_Surface	*screen;
 
  screen = menu_init();
}
