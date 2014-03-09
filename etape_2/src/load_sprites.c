/*
** load_sprites.c for  in /home/guerot_a/depots/T2Rush1/etape_1
**
** Made by guerot_a
** Login   <guerot_a@epitech.net>
**
** Started on  Sat Mar  8 00:11:15 2014 guerot_a
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Sun Mar  9 15:05:24 2014 genes_k
=======
** Last update Sun Mar  9 15:00:09 2014 guerot_a
>>>>>>> d241fdcc968283fe9171686b0617e51c70226136
=======
** Last update Sun Mar  9 15:24:50 2014 guerot_a
>>>>>>> 1cda97ee16f04547ac1af0813b2653d677e2c983
=======
** Last update Sun Mar  9 16:09:29 2014 guerot_a
>>>>>>> 52f3427d4f8f4bd3da5a85367dfbebe366ba14fd
*/

#include "epikong.h"

t_spritepair sprites[] =
  {
    {'w', "Wall", NULL},
    {'s', "Ladder", NULL},
    {'i', "Mario", NULL},
    {'i', "MarioBack", NULL},
    {'i', "MarioJump", NULL},
    {'i', "MarioJumpBack", NULL},
    {'m', "Monster", NULL},
    {'m', "MonsterBack", NULL},
    {'k', "Key", NULL},
    {'o', "Exit", NULL},
    {'1', "Corner_TL", NULL},
    {'2', "Top", NULL},
    {'3', "Corner_TR", NULL},
    {'4', "Left", NULL},
    {'5', "Right", NULL},
    {'6', "Corner_BL", NULL},
    {'7', "Bot", NULL},
    {'8', "Corner_BR", NULL},
    {'d', "Death", NULL},
    {'l', "Life", NULL},
    {'g', "Gun", NULL},
    {'p', "Projectile", NULL},
    {'M', "Monster2", NULL},
    {'M', "MonsterBack2", NULL},
    {'c', "Cloud", NULL},
    {'r', "Iron", NULL},
    {'x', "Explosion", NULL},
    {'B', "Boss", NULL},
    {'B', "BossBack", NULL},
    {'t', "Trap_up", NULL},
    {'\0', "", NULL}
  };

void	set_alpha()
{
  int	i;

  i = 0;
  while (sprites[i].img)
    {
      SDL_SetColorKey(sprites[i].img, SDL_SRCCOLORKEY, COLOR_ALPHA);
      i++;
    }
}

void	load_sprites()
{
  sprites[0].img = xSDL_LoadBMP("Sprites/Wall.bmp");
  sprites[1].img = xSDL_LoadBMP("Sprites/Ladder.bmp");
  sprites[2].img = xSDL_LoadBMP("Sprites/Mario_1.bmp");
  sprites[3].img = xSDL_LoadBMP("Sprites/Mario_Back_1.bmp");
  sprites[4].img = xSDL_LoadBMP("Sprites/Mario_Jump.bmp");
  sprites[5].img = xSDL_LoadBMP("Sprites/Mario_Jump_Back.bmp");
  sprites[6].img = xSDL_LoadBMP("Sprites/Turtle.bmp");
  sprites[7].img = xSDL_LoadBMP("Sprites/Turtle_Back.bmp");
  sprites[8].img = xSDL_LoadBMP("Sprites/Key.bmp");
  sprites[9].img = xSDL_LoadBMP("Sprites/Exit.bmp");
  sprites[10].img = xSDL_LoadBMP("Sprites/Pipe_Corner_TL.bmp");
  sprites[11].img = xSDL_LoadBMP("Sprites/Pipe_Top.bmp");
  sprites[12].img = xSDL_LoadBMP("Sprites/Pipe_Corner_TR.bmp");
  sprites[13].img = xSDL_LoadBMP("Sprites/Pipe_Left.bmp");
  sprites[14].img = xSDL_LoadBMP("Sprites/Pipe_Right.bmp");
  sprites[15].img = xSDL_LoadBMP("Sprites/Pipe_Corner_BL.bmp");
  sprites[16].img = xSDL_LoadBMP("Sprites/Pipe_Bot.bmp");
  sprites[17].img = xSDL_LoadBMP("Sprites/Pipe_Corner_BR.bmp");
  sprites[18].img = xSDL_LoadBMP("Sprites/Mario_Death.bmp");
  sprites[19].img = xSDL_LoadBMP("Sprites/Life.bmp");
  sprites[20].img = xSDL_LoadBMP("Sprites/Flower_Fire.bmp");
  sprites[21].img = xSDL_LoadBMP("Sprites/Fire.bmp");
  sprites[22].img = xSDL_LoadBMP("Sprites/Monster.bmp");
  sprites[23].img = xSDL_LoadBMP("Sprites/Monster_Back.bmp");
  sprites[24].img = xSDL_LoadBMP("Sprites/Cloud_Platform.bmp");
  sprites[25].img = xSDL_LoadBMP("Sprites/Iron_Platform.bmp");
  sprites[26].img = xSDL_LoadBMP("Sprites/Explosion.bmp");
  sprites[27].img = xSDL_LoadBMP("Sprites/Anti_Mario.bmp");
  sprites[28].img = xSDL_LoadBMP("Sprites/Anti_Mario_Back.bmp");
  sprites[29].img = xSDL_LoadBMP("Sprites/Trap_Up.bmp");
  set_alpha();
}
