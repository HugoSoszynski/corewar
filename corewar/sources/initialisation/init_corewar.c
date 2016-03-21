/*
** init_corewar.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:51:42 2016 Hugo SOSZYNSKI
** Last update Mon Mar 21 18:28:27 2016 corsin_a
*/

#include	<stddef.h>
#include	"corewar.h"

int		init_corewar(t_corewar *corewar,
			     int ac, char **av)
{
  t_options	options;

  (void)corewar;
  if (init_options(ac, av, &options) != SUCCESS)
    return (ERROR);
  /*
  if (init_champ(corewar, ac - 1, &av[1]) != SUCCESS)
    return (ERROR);
  */
  return (SUCCESS);
}
