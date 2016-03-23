/*
** live.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:00 2016 corsin_a
** Last update Wed Mar 23 15:52:00 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_live(char	opcode)
{
  if (opcode != 128)
    return (ERROR);
  return (SUCCESS);
}

void		op_live(t_corewar	*corewar,
			t_process_list	*current)
{
  int		cpt;

  cpt = -1;
  while (++cpt < corewar->nb_champions)
    {
      if (corewar->champion[cpt].nb_champion == current->process.nb_champion)
	{
	  if (corewar->champions_alive[cpt] != IS_DEAD)
	    {
	      corewar->champions_alive[cpt] = IS_ALIVE;
	    }
	  return ;
	}
    }
}
