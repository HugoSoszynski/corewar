/*
** live.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:00 2016 corsin_a
** Last update Wed Mar 23 19:12:39 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_live(char	opcode)
{
  return (SUCCESS);
}

void		copy_op_live(t_corewar *corewar,
			     t_process_list *current)
{
  int		cpt;

  cpt = 0;
  current->instruction.arg[0] = 0;
  while (cpt < 4)
    {
      current->instruction.arg[0] = current->instruction.arg[0] << 8;
      current->instruction.arg[0] +=
      corewar->mem[(current->process.pc + cpt) % MEM_SIZE];
      ++cpt;
    }
  if (!IS_LIT_ENDIAN)
    my_reverse_bytes(&current->instruction.arg[0], sizeof(int));
  current->instruction.opcode = 0;
  current->instruction.correct = false;
  current->cycle = ((t_op_tab*)(corewar->op_tab))[0].cycle;
}

void		exec_op_live(t_corewar	*corewar,
			     t_process_list	*current)
{
  int		cpt;

  cpt = -1;
  current->process.pc = (current->process.pc + 5) % MEM_SIZE;
  while (++cpt < corewar->nb_champions)
    {
      if (corewar->champion[cpt].nb_champion == current->process.nb_champion)
	{
	  if (corewar->champions_alive[cpt] != IS_DEAD)
	    {
	      corewar->nb_live += 1;
	      corewar->champions_alive[cpt] = IS_ALIVE;
	    }
	  return ;
	}
    }
}
