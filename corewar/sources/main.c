/*
** main.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:06:28 2016 Hugo SOSZYNSKI
** Last update Mon Mar 21 11:59:21 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	"corewar.h"

int		main(int ac, char **av)
{
  t_corewar	corewar;

  if (ac == 0 && av == NULL)
    return (ERROR);
  init_corewar(&corewar);
  return (SUCCESS);
}
