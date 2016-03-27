/*
** intro.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/graphics/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sun Mar 27 23:05:28 2016 corsin_a
** Last update Sun Mar 27 23:25:21 2016 corsin_a
*/

#include		"corewar.h"

t_bunny_response	introloop(void	*_data)
{
  t_bonus		*data;
  t_bunny_position	pos;
  static int		i = 1;

  data = _data;
  pos.x = 0;
  pos.y = 0;
  tekblit(data->pix, data->bg, &pos);
  pos.x = data->bg->clipable.buffer.width / 2 -
      data->salt->clipable.buffer.width / 2;
  pos.y = data->bg->clipable.buffer.height / 2 -
      data->salt->clipable.buffer.height / 2 - 50;
  gst_alpha(data->salt, i);
  tekblit(data->pix, data->salt, &pos);
  if (i > 155)
    {
      gst_alpha(data->salt_title, i - 155);
      pos.x = data->bg->clipable.buffer.width / 2 -
          data->salt_title->clipable.buffer.width / 2;
      pos.y = data->bg->clipable.buffer.height / 2 -
          data->salt_title->clipable.buffer.height / 2 + 200;
      tekblit(data->pix, data->salt_title, &pos);
    }
  if (i > 200)
    {
      gst_alpha(data->titre, i - 200);
      pos.x = data->bg->clipable.buffer.width / 2 -
	  data->titre->clipable.buffer.width / 2;
      pos.y = 0;
      tekblit(data->pix, data->titre, &pos);
    }
  if (i > 700)
    return (EXIT_ON_SUCCESS);
  bunny_blit(&data->win->buffer,
	     &data->pix->clipable,
	     NULL);
  bunny_display(data->win);
  ++i;
  return (GO_ON);
}
