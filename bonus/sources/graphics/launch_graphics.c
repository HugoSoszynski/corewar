/*
** launch_graphics.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/graphics/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Sat Mar 26 16:03:14 2016 corsin_a
** Last update Sun Mar 27 05:42:11 2016 corsin_a
*/

#include		"corewar.h"

void			launch_graphics(t_bonus	*data)
{
  show_interface(data);
  show_cycle(data);
  show_mem(data);
  show_champ(data);
}
