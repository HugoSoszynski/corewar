/*
** fork.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:32 2016 corsin_a
** Last update Sun Mar 27 20:01:13 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_fork(char	opcode)
{
  (void)opcode;
  return (SUCCESS);
}

void		copy_op_fork(t_corewar *corewar,
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
  current->instruction.opcode = 0;
}

void		exec_op_fork(t_corewar	*corewar,
			     t_process_list	*current)
{
  (void)corewar;
  if (current->instruction.correct)
    {
      clone_process(current, (short)(current->instruction.arg[0]) % IDX_MOD);
    }
  current->process.pc = (current->process.pc + 3) % MEM_SIZE;
}
