/*
** main.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:06:28 2016 Hugo SOSZYNSKI
** Last update Tue Mar 22 11:17:41 2016 corsin_a
*/

#include	<stddef.h>
#include	"corewar.h"

int		main(int 	argc,
		     char 	*argv[])
{
  t_corewar	corewar;

  if (there_is_help(argc, argv) == SUCCESS)
    {
      aff_help(0);
      return (SUCCESS);
    }
  corewar.process_list = NULL;
  if (init_corewar(&corewar, argc, argv) != SUCCESS)
    return (aff_help(1));
  return (SUCCESS);
}
