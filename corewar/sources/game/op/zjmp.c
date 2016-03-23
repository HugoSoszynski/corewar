/*
** zjmp.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:32 2016 corsin_a
** Last update Wed Mar 23 19:14:42 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_zjmp(char	opcode)
{
  printf("ZJMP\n");
  return (SUCCESS);
}

void		copy_op_zjmp(t_corewar *corewar,
			     t_process_list *current)
{
  current->instruction.opcode = 192;
  copy_args(corewar, current);
}

void		exec_op_zjmp(t_corewar	*corewar,
			     t_process_list	*current)
{
  if (current->process.carry == 1)
    {
      current->process.pc = ((current->process.pc +
			      (current->instruction.arg[0] % IDX_MOD))
			     % MEM_SIZE);
    }
  else
    current->process.pc = (current->process.pc + 3) % MEM_SIZE;
}
