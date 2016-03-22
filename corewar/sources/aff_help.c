/*
** aff_help.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Tue Mar 22 10:57:59 2016 corsin_a
** Last update Tue Mar 22 11:17:29 2016 corsin_a
*/

#include	<unistd.h>
#include	"corewar.h"

int		there_is_help(int	argc,
			      char	*argv[])
{
  int		cpt;

  cpt = 1;
  while (cpt < argc)
    {
      if (my_strcmp(argv[cpt], "-h") || my_strcmp(argv[cpt], "--help"))
	return (SUCCESS);
      ++cpt;
    }
  return (ERROR);
}

int		aff_help(int		a)
{
  if (a)
    write(1, "\n", 1);
  write(1, "./corewar [-dump nbr_cycle] [[-n prog_nbb] \
[-a load_adress] prog_name] ...\n", 75);
  return (ERROR);
}
