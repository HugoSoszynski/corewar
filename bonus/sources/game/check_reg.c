/*
** check_reg.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Fri Mar 25 00:38:24 2016 corsin_a
** Last update Fri Mar 25 01:03:37 2016 corsin_a
*/

#include	"corewar.h"

void		check_reg(t_process_list	*current)
{
  int		type;
  int		cpt;

  cpt = 0;
  while (cpt < 3)
    {
      if ((type = current->instruction.opcode >> (6 - cpt * 2) & 3) > 0)
	{
	  if (type == 1 && (current->instruction.arg[cpt] < 1 ||
			    current->instruction.arg[cpt] > REG_NUMBER))
	    {
	      current->instruction.correct = false;
	      return ;
	    }
	}
      else
	return ;
      ++cpt;
    }
}
