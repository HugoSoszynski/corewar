/*
** sub.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:24 2016 corsin_a
** Last update Thu Mar 24 14:16:57 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_sub(char	opcode)
{
  printf("SUB\n");
  if (opcode != 84)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_sub(t_corewar *corewar,
			    t_process_list *current)
{
  copy_args(corewar, current);
}

void		exec_op_sub(t_corewar	*corewar,
			    t_process_list	*current)
{
  int		nb1;
  int		nb2;
  int		*reg;

  if (current->instruction.correct)
    {
      nb1 = current->process.reg[current->instruction.arg[0] - 1];
      nb2 = current->process.reg[current->instruction.arg[1] - 1];
      reg = &current->process.reg[current->instruction.arg[2] - 1];
      *reg = nb1 + nb2;
    }
  current->process.carry = (char)current->instruction.correct;
  move_pc(current);
}
