/*
** tekpixel.c for liblapin in /home/corsin_a/Travail/Infographie/noise_2020
**
** Made by corsin_a
** Login   <corsin_a@epitech.net>
**
** Started on  Sun Nov 22 15:15:25 2015 corsin_a
** Last update Sat Mar 19 15:01:25 2016 corsin_a
*/

#include	<lapin.h>

void		tekpixel(t_bunny_pixelarray	*pix,
			 t_bunny_position	*pos,
			 t_color		*color)
{
  if (pos->x < pix->clipable.clip_width && pos->y < pix->clipable.clip_height
      && pos->x >= 0 && pos->y >= 0)
    ((t_color *)(pix->pixels))
      [(pix->clipable.clip_width * pos->y) + pos->x] = *color;
}
