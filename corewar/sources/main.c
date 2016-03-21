/*
** main.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:06:28 2016 Hugo SOSZYNSKI
** Last update Mon Mar 21 17:24:34 2016 corsin_a
*/

#include	<stddef.h>
#include	"corewar.h"

int		main(int 	argc,
		     char 	*argv[])
{
  t_corewar	corewar;

  corewar.process_list = NULL;
  if (argc == 1)
    return (ERROR);
  else
    {
      if (init_corewar(&corewar, argc, argv) != SUCCESS)
	return (ERROR);
    }
  return (SUCCESS);
}
