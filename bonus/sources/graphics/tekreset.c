/*
** tekwindow.c for liblapin in /home/corsin_a/Travail/Infographie/gfx_fdf1/src
**
** Made by corsin_a
** Login   <corsin_a@epitech.net>
**
** Started on  Tue Nov 24 09:32:23 2015 corsin_a
** Last update Wed Feb 17 09:30:39 2016 corsin_a
*/

#include		<lapin.h>
#include		"header.h"

void			tekreset(t_bunny_pixelarray	*pix,
				 t_color		*color)
{
  int			cpt1;
  int			cpt2;
  t_bunny_position	pos;

  cpt1 = 0;
  while (cpt1 < pix->clipable.clip_height)
    {
      pos.y = cpt1;
      cpt2 = 0;
      while (cpt2 < pix->clipable.clip_width)
	{
	  pos.x = cpt2;
	  tekpixel(pix, &pos, color);
	  ++cpt2;
	}
      ++cpt1;
    }
}
