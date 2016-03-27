/*
** show_cycle.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/graphics/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sun Mar 27 03:02:59 2016 corsin_a
** Last update Sun Mar 27 04:04:54 2016 corsin_a
*/

#include		"corewar.h"
#include		<stdio.h>

void			show_cycle(t_bonus	*data)
{
  t_bunny_position	pos;
  t_color		color;
  char			str[1000];

  pos.x = 970;
  pos.y = 110;
  color.full = 4294440704;
  tektext(data, &pos, "STATS :", &color);
  pos.y = 210;
  sprintf(str, "Actual cycle :\n%ld\n\nCycle to die :\n%d\n\nCycle to next die :\n%d\n\nNumber live :\n%d", data->corewar.actual_cycle, data->corewar.cycle_to_die, data->corewar.cycle_to_die - data->corewar.cycle_passed, data->corewar.live_nb);
  tektext(data, &pos, str, &color);
}
