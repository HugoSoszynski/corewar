/*
** tektext.c for tekgui in /home/corsin_a/Travail/Infographie/gfx_tekgui/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Mon Feb 15 12:47:55 2016 corsin_a
** Last update Sun Mar 27 03:40:25 2016 corsin_a
*/

#include		<lapin.h>
#include		"corewar.h"

static void		put_letter(t_bonus		*data,
				   char			c,
				   t_bunny_position	*initial,
				   t_color		*color)
{
  t_bunny_position	char_pos;
  t_bunny_position	temp;
  t_color		col;

  char_pos.y = 0;
  while (char_pos.y < data->font->clipable.clip_height)
    {
      char_pos.x = c * 10;
      while (char_pos.x < c * 10 + 10)
	{
	  col.full = tekgetcolor(data->font, &char_pos);
	  if (col.argb[3] != 0)
	    {
	      temp.x = char_pos.x % c + initial->x;
	      temp.y = char_pos.y + initial->y;
	      tekpixel(data->pix, &temp, color);
	    }
	  ++char_pos.x;
	}
      ++char_pos.y;
    }
}

static void		new_pos(const t_bunny_position	*initial,
				t_bunny_position	*pos)
{
  (initial) ? (pos->x = initial->x) : (pos->x = 0);
  pos->y += 18;
}

void			tektext(t_bonus			*data,
				const t_bunny_position	*initial,
				char			*str,
				t_color			*color)
{
  int			cpt;
  int			len;
  t_bunny_position	pos;

  len = my_strlen(str);
  cpt = 0;
  (initial) ? (pos.y = initial->y) : (pos.y = 0);
  (initial) ? (pos.x = initial->x) : (pos.x = 0);
  while (cpt < len)
    {
      if (pos.x > data->pix->clipable.clip_width - 5)
	new_pos(initial, &pos);
      if (str[cpt] != '\n')
	{
	  put_letter(data, str[cpt], &pos, color);
	  pos.x += 12;
	}
      else
	new_pos(initial, &pos);
      ++cpt;
    }
}
