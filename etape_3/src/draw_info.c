/*
** draw_info.c for  in /home/guerot_a/depots/T2Rush1/etape_2
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sun Mar  9 01:27:28 2014 guerot_a
** Last update Sun Mar  9 15:59:28 2014 guerot_a
*/

#include "epikong.h"

void	draw_life(t_objlist* objlist, SDL_Surface* zone_infos)
{
  int		i;
  SDL_Surface*	life;
  SDL_Rect	rect;

  life = get_sprite_by_str("Life");
  rect.y = HEIGHT_INFOS / 2 - life->h / 2;
  rect.x = OFFSET_LEFT_LIFE;
  i = 0;
  while (i < objlist->player.life)
    {
      SDL_BlitSurface(life, NULL, zone_infos, &rect);
      rect.x += life->w + PADDING_LIFE;
      i++;
    }
}

void	draw_key(t_objlist* objlist, SDL_Surface* zone_infos)
{
  SDL_Rect	rect;
  SDL_Surface*	key;

  if (!objlist->player.key)
    return;
  key = get_sprite_by_str("Key");
  rect.x = OFFSET_LEFT_KEY;
  rect.y = HEIGHT_INFOS / 2 - key->h / 2;
  SDL_BlitSurface(key, NULL, zone_infos, &rect);
}

void	draw_gun(t_objlist* objlist, SDL_Surface* zone_infos)
{
  SDL_Rect	rect;
  SDL_Surface*	gun;

  if (!objlist->player.equiped)
    return;
  gun = get_sprite_by_str("Gun");
  rect.x = OFFSET_LEFT_GUN;
  rect.y = HEIGHT_INFOS / 2 - gun->h / 2;
  SDL_BlitSurface(gun, NULL, zone_infos, &rect);
}

void	draw_info(t_objlist *objlist, SDL_Surface* screen,
		  SDL_Surface* zone_infos)
{
  SDL_Rect	rect;

  (void) objlist;
  rect.x = 0;
  rect.y = screen->h - HEIGHT_INFOS;
  SDL_FillRect(zone_infos, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  draw_life(objlist, zone_infos);
  draw_key(objlist, zone_infos);
  draw_gun(objlist, zone_infos);
  SDL_BlitSurface(zone_infos, NULL, screen, &rect);
}
