/*
** or.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:11 2016 corsin_a
** Last update Sat Mar 26 11:14:01 2016 Hugo SOSZYNSKI
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_or(unsigned char opcode)
{
  printf("CHECK OR\n");
  if (opcode != 84 && opcode != 100 && opcode != 116 && opcode != 148 &&
      opcode != 164 && opcode != 180 && opcode != 212 && opcode != 228 &&
      opcode != 244)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_or(t_corewar *corewar,
			   t_process_list *current)
{
  printf("COPY OR\n");
  copy_args(corewar, current);
}

void		exec_op_or(t_corewar		*corewar,
			   t_process_list	*current)
{
  int		nb1;
  int		nb2;
  int		*reg;

  (void)corewar;
  printf("EXEC OR\n");
  if (current->instruction.correct)
    {
      printf("CORRECT OR\n");
      if (current->instruction.type_arg[0] == 1)
	nb1 = current->process.reg[current->instruction.arg[0] - 1];
      else
	nb1 = current->instruction.arg[0];
      if (current->instruction.type_arg[1] == 1)
	nb2 = current->process.reg[current->instruction.arg[1] - 1];
      else
	nb2 = current->instruction.arg[1];
      reg = &current->process.reg[current->instruction.arg[2] - 1];
      *reg = nb1 | nb2;
      printf("RESULT OR REG : %d\n", current->process.reg[current->instruction.arg[2] - 1]);
    }
  current->process.carry = (char)current->instruction.correct;
  move_pc(current);
}
