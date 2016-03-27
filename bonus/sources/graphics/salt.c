/*
** salt.c for  in /home/pillon_m/corewar/CPE_2015_corewar/bonus/sources/graphics
** 
** Made by Maxime Pillon
** Login   <pillon_m@epitech.net>
** 
** Started on  Sun Mar 27 23:04:17 2016 
** Last update Sun Mar 27 23:15:42 2016 
*/

#include	<lapin.h>
#include	<lapin_enum.h>

void		gst_alpha(t_bunny_pixelarray *pix, int alpha)
{
  t_bunny_position	pos;
  t_color		color;

  if (alpha > 255)
    alpha = 255;
  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
	  color.full = ((unsigned int *)pix->pixels)[(pos.y * pix->clipable.clip_width +
						      pos.x)];
	  color.argb[3] = alpha;
	  ((unsigned int *)pix->pixels)[(pos.y * pix->clipable.clip_width +
					 pos.x)] = color.full;
	  pos.x++;
	}
      pos.y++;
    }
}
