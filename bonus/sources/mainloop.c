/*
** mainloop.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/bonus/sources/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
**
** Started on  Fri Mar 25 17:01:13 2016 corsin_a
** Last update Sat Mar 26 18:07:23 2016 corsin_a
*/

#include		"corewar.h"

t_bunny_response	mainloop(void	*_data)
{
  t_bonus		*data;

  data = _data;
  if (launch_corewar(&data->corewar) == SUCCESS)
    return (EXIT_ON_SUCCESS);
  if (data->corewar.actual_cycle % 9 == 0)
    {
      launch_graphics(data);
      bunny_blit(&data->win->buffer,
		 &data->pix->clipable,
		 NULL);
      bunny_display(data->win);
    }
  return (GO_ON);
}
