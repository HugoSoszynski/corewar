/*
** sub.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:24 2016 corsin_a
** Last update Sat Mar 26 11:16:25 2016 Hugo SOSZYNSKI
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_sub(char	opcode)
{
  printf("CHECK SUB\n");
  if (opcode != 84)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_sub(t_corewar *corewar,
			    t_process_list *current)
{
  printf("COPY SUB\n");
  copy_args(corewar, current);
  check_reg(current);
}

void		exec_op_sub(t_corewar	*corewar,
			    t_process_list	*current)
{
  int		nb1;
  int		nb2;
  int		*reg;

  printf("EXEC SUB\n");
  printf("%d\n", current->instruction.opcode);
  printf("%d , %d , %d\n",
	 current->instruction.arg[0],
	 current->instruction.arg[1],
	 current->instruction.arg[2]);
  (void)corewar;
  if (current->instruction.correct)
    {
      printf("CORRECT SUB\n");
      nb1 = current->process.reg[current->instruction.arg[0] - 1];
      nb2 = current->process.reg[current->instruction.arg[1] - 1];
      reg = &current->process.reg[current->instruction.arg[2] - 1];
      *reg = nb1 - nb2;
      printf("RESULT SUB REG : %d\n", current->process.reg[current->instruction.arg[2] - 1]);
    }
  current->process.carry = (char)current->instruction.correct;
  move_pc(current);
}
