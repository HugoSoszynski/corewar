/*
** lfork.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:55 2016 corsin_a
** Last update Thu Mar 24 15:31:15 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_lfork(char	opcode)
{
  printf("LFORK\n");
  if (opcode != 128)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_lfork(t_corewar *corewar,
			      t_process_list *current)
{

}

void		exec_op_lfork(t_corewar	*corewar,
			      t_process_list	*current)
{
  clone_process(current, current->instruction.arg[0]);
  current->process.pc = (current->process.pc + 3) % MEM_SIZE;
}
