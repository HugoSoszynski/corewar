/*
** fork.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:32 2016 corsin_a
** Last update Thu Mar 24 15:45:39 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_fork(char	opcode)
{
  printf("FORK\n");
  (void)opcode;
  return (SUCCESS);
}

void		copy_op_fork(t_corewar *corewar,
			     t_process_list *current)
{
  int		cpt;

  cpt = 0;
  current->instruction.arg[0] = 0;
  while (cpt < 4)
    {
      current->instruction.arg[0] = current->instruction.arg[0] << 8;
      current->instruction.arg[0] +=
      corewar->mem[(current->process.pc + cpt + 1) % MEM_SIZE];
      ++cpt;
    }
  if (!IS_LIT_ENDIAN)
    my_reverse_bytes(&current->instruction.arg[0], sizeof(int));
  current->instruction.opcode = 0;
  current->instruction.correct = false;
  current->cycle = ((t_op_tab*)(corewar->op_tab))[0].cycle;
}

void		exec_op_fork(t_corewar	*corewar,
			     t_process_list	*current)
{
  (void)corewar;
  clone_process(current, current->instruction.arg[0] % IDX_MOD);
  current->process.pc = (current->process.pc + 5) % MEM_SIZE;
}
