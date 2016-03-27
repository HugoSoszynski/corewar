/*
** lfork.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:55 2016 corsin_a
** Last update Sun Mar 27 21:44:37 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_lfork(char	opcode)
{
  (void)opcode;
  return (SUCCESS);
}

void		copy_op_lfork(t_corewar *corewar,
			      t_process_list *current)
{
  int		cpt;

  cpt = 0;
  current->instruction.arg[0] = 0;
  while (cpt < 2)
    {
      current->instruction.arg[0] = (short)(current->instruction.arg[0] << 8);
      current->instruction.arg[0] +=
      corewar->mem[verif_pc(current->process.pc + cpt + 1)];
      ++cpt;
    }
  if (!IS_LIT_ENDIAN)
    my_reverse_bytes(&current->instruction.arg[0], sizeof(short));
}

void		exec_op_lfork(t_corewar	*corewar,
			      t_process_list	*current)
{
  (void)corewar;
  if (current->instruction.correct)
    {
      if (clone_process(current, (short)current->instruction.arg[0]) != ERROR)
	current->process.carry = 1;
      ++corewar->champion[current->process.cpt].nb_process;
    }
  current->process.pc = (current->process.pc + 3) % MEM_SIZE;
}
