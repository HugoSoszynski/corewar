/*
** aff_help.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Tue Mar 22 10:57:59 2016 corsin_a
** Last update Tue Mar 22 11:03:01 2016 corsin_a
*/

#include	<unistd.h>
#include	"corewar.h"

int		aff_help()
{
  write(1, "\n./corewar [-dump nbr_cycle] [[-n prog_nbb] \
[-a load_adress] prog_name] ...\n", 76);
  return (ERROR);
}
