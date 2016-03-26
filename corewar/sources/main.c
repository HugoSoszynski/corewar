/*
** main.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:06:28 2016 Hugo SOSZYNSKI
** Last update Sat Mar 26 21:30:59 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"corewar.h"

int		main(int 	argc,
		     char 	*argv[])
{
  t_corewar	corewar;
  int		cpt;

  if (check_h() != SUCCESS)
    return (ERROR);
  if (there_is_help(argc, argv) == SUCCESS)
    {
      aff_help(0);
      return (SUCCESS);
    }
  if (init_corewar(&corewar, argc, argv) != SUCCESS)
    return (aff_help(1));
  if (prepare_corewar(&corewar) != SUCCESS)
    return (ERROR);
  if (launch_corewar(&corewar) != SUCCESS)
    return (ERROR);
  free_processlist(corewar.process_list);
  cpt = 0;
  while (cpt < corewar.nb_champions)
    {
      free(corewar.champion[cpt].prog);
      ++cpt;
    }
  free(corewar.op_tab);
  return (SUCCESS);
}
