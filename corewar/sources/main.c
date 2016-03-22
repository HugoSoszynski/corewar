/*
** main.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 21 10:06:28 2016 Hugo SOSZYNSKI
** Last update Tue Mar 22 22:42:49 2016 corsin_a
*/

#include	<stddef.h>
#include	"corewar.h"

int		main(int 	argc,
		     char 	*argv[])
{
  t_corewar	corewar;
  int		cpt;

  if (REG_NUMBER < 1 || REG_SIZE < 4 || CYCLE_TO_DIE < 1
      || CYCLE_DELTA < 0 || NBR_LIVE < 1 || PROG_NAME_LENGTH < 1
      || COMMENT_LENGTH < 1 || IND_SIZE < 1 || DIR_SIZE < 1
      || T_REG < 1 || T_DIR < 1 || T_IND < 1)
    return (error_message("Error op.h"));
  if (there_is_help(argc, argv) == SUCCESS)
    {
      aff_help(0);
      return (SUCCESS);
    }
  if (init_corewar(&corewar, argc, argv) != SUCCESS)
    return (aff_help(1));
  if (prepare_corewar(&corewar) != SUCCESS)
    return (ERROR);
  cpt = 0;
  #include	<stdio.h>
  while (cpt < MEM_SIZE)
    {
      printf("Ox%.2x ", corewar.mem[cpt]);
      if ((cpt + 1) % 20 == 0 && cpt != 0)
	printf("\n");
      ++cpt;
    }
  if (launch_corewar(&corewar) != SUCCESS)
    return (ERROR);
  return (SUCCESS);
}
