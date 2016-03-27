/*
** show_champ.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/graphics/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sun Mar 27 05:42:29 2016 corsin_a
** Last update Sun Mar 27 07:12:18 2016 corsin_a
*/

#include		<stdio.h>
#include		"corewar.h"

void			show_champ(t_bonus	*data)
{
  t_bunny_position	pos;
  t_color		color;
  int			cpt;
  char			str[1000];

  pos.x = 40;
  cpt = 0;
  while (cpt < data->corewar.nb_champions)
    {
      pos.y = 455;
      color.full = data->corewar.champion[cpt].color;
      sprintf(str, "%s\n\nNumber : %d\nProcessus : %d", data->corewar.champion[cpt].header.prog_name,
	      data->corewar.champion[cpt].nb_champion, data->corewar.champion[cpt].nb_process);
      tektext(data, &pos, str, &color);
      pos.y += 100;
      if (data->corewar.champions_alive[cpt] == IS_DEAD)
	{
	  color.full = RED;
	  tektext(data, &pos, "DEAD", &color);
	}
      else if (data->corewar.champions_alive[cpt] == IS_ALIVE)
	{
	  color.full = GREEN;
	  tektext(data, &pos, "ALIVE", &color);
	}
      else
	{
	  color.full = YELLOW;
      	  tektext(data, &pos, "WAITING", &color);
	}
      pos.x += 300;
      ++cpt;
    }
}
