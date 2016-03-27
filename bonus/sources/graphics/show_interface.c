/*
** show_interface.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/graphics/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sun Mar 27 03:02:33 2016 corsin_a
** Last update Sun Mar 27 03:04:23 2016 corsin_a
*/

#include		"corewar.h"

void			show_interface(t_bonus	*data)
{
  t_bunny_position	pos;
  t_color		color;

  pos.x = 0;
  pos.y = 0;
  color.full = BLACK;
  tekreset(data->pix, &color);
  tekblit(data->pix, data->bg, &pos);
  pos.x = data->bg->clipable.buffer.width / 2 - data->titre->clipable.buffer.width / 2;
  tekblit(data->pix, data->titre, &pos);
  pos.x = data->bg->clipable.buffer.width / 2 - data->cadre->clipable.buffer.width / 2;
  pos.y = data->bg->clipable.buffer.height - data->cadre->clipable.buffer.height - 20;
  tekblit(data->pix, data->cadre, &pos);
}
