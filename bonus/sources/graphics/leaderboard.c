/*
** leaderboard.c for corewar.c in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/graphics/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sun Mar 27 19:53:15 2016 corsin_a
** Last update Sun Mar 27 21:04:11 2016 corsin_a
*/

#include		"corewar.h"

static void		write_winner(t_bonus 	*data)
{
  int			cpt;
  t_bunny_position	pos;
  t_color		color;

  color.full = 4294440704;
  if (data->corewar.nb_champions < 2)
    return ;
  cpt = -1;
  while (++cpt < data->corewar.nb_champions)
    {
      if (data->corewar.champions_alive[cpt] == IS_ALIVE)
	{
          pos.x = data->bg->clipable.buffer.width / 2 - (my_strlen(data->corewar.champion[cpt].header.prog_name) - 1) * 12 / 2;
          pos.y = data->bg->clipable.buffer.height / 2;
	  tektext(data, &pos, data->corewar.champion[cpt].header.prog_name, &color);
	  return ;
	}
    }
  pos.x = data->bg->clipable.buffer.width / 2 - (my_strlen("No winner") - 1) * 12 / 2;
  pos.y = data->bg->clipable.buffer.height / 2;
  tektext(data, &pos, "No winner", &color);
}

t_bunny_response	leaderboard(void	*_data)
{
  t_bonus		*data;
  t_bunny_position	pos;

  data = _data;
  pos.x = 0;
  pos.y = 0;
  tekblit(data->pix, data->bg, &pos);
  pos.x = data->bg->clipable.buffer.width / 2 - data->titre->clipable.buffer.width / 2;
  tekblit(data->pix, data->titre, &pos);
  write_winner(data);
  bunny_blit(&data->win->buffer,
	     &data->pix->clipable,
	     NULL);
  bunny_display(data->win);
  return (GO_ON);
}
