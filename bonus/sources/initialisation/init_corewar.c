/*
** init_corewar.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:51:42 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 04:00:32 2016 corsin_a
*/

#include	<stddef.h>
#include	"corewar.h"

int		init_corewar(t_bonus *data,
			     int ac, char **av)
{
  t_options	options;

  if (init_options(ac, av, &options) != SUCCESS)
    return (ERROR);
  if (init_champ(&data->corewar, &options) != SUCCESS)
    return (ERROR);
  if (champ_imcomp(&data->corewar) != SUCCESS)
    return (ERROR);
  if (fill_champions(&data->corewar) != SUCCESS)
    return (ERROR);
  if (init_graphics(data) != SUCCESS)
    return (ERROR);
  return (SUCCESS);
}
