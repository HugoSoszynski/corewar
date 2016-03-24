/*
** lldi.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:06 2016 corsin_a
** Last update Thu Mar 24 15:16:27 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_lldi(char	opcode)
{
  printf("LLDI\n");
  if (opcode != 84 && opcode != 148 && opcode != 164 && opcode != 212 &&
      opcode != 228 && opcode != 100)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_lldi(t_corewar *corewar,
			     t_process_list *current)
{
  int		temp;

  temp = current->instruction.opcode;
  current->instruction.opcode = 244;
  copy_args(corewar, current);
  current->instruction.opcode = temp;
}

void		exec_op_lldi(t_corewar	*corewar,
			     t_process_list	*current)
{
  
}
