/*
** tekblit.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/graphics/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sun Mar 27 01:28:10 2016 corsin_a
** Last update Sun Mar 27 01:30:51 2016 corsin_a
*/

#include		<lapin.h>
#include		"corewar.h"

static void		put_pixel(t_bunny_pixelarray	*out,
				  t_bunny_pixelarray	*in,
				  t_bunny_position	*pos_out,
				  t_bunny_position	*pos_in)
{
  t_color		color_in;
  t_color		color_out;
  double		diff;

  color_in.full = tekgetcolor(in, pos_in);
  if (color_in.argb[3] == 255)
    tekpixel(out, pos_out, &color_in);
  else if (color_in.argb[3] != 0)
    {
      diff = (double)(color_in.argb[3]) / 255.0;
      color_out.full = tekgetcolor(out, pos_out);
      color_in.argb[0] = color_in.argb[0] * diff +
	color_out.argb[0] * (1 - diff);
      color_in.argb[1] = color_in.argb[1] * diff +
	color_out.argb[1] * (1 - diff);
      color_in.argb[2] = color_in.argb[2] * diff +
	color_out.argb[2] * (1 - diff);
      tekpixel(out, pos_out, &color_in);
    }
}

void			tekblit(t_bunny_pixelarray *out,
				t_bunny_pixelarray *in,
				const t_bunny_position *pos)
{
  t_bunny_position	pos_in;
  t_bunny_position	pos_out;

  pos_in.y = in->clipable.clip_y_position;
  pos_out.y = pos->y;
  while (pos_out.y < out->clipable.buffer.height &&
	 pos_in.y < in->clipable.clip_y_position + in->clipable.clip_height &&
	 pos_in.y < in->clipable.buffer.height)
    {
      pos_in.x = in->clipable.clip_x_position;
      pos_out.x = pos->x;
      while (pos_out.x < out->clipable.buffer.width &&
	     pos_in.y < in->clipable.clip_y_position + in->clipable.clip_height &&
	     pos_in.y < in->clipable.buffer.height)
	{
	  put_pixel(out, in, &pos_out, &pos_in);
	  ++pos_in.x;
	  ++pos_out.x;
	}
      ++pos_in.y;
      ++pos_out.y;
    }
}
