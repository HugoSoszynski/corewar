/*
** sti.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:21 2016 corsin_a
** Last update Thu Mar 24 22:10:42 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_sti(char	opcode)
{
  printf("CHECK STI\n");
  if (opcode != 84 && opcode != 100 && opcode != 104 && opcode != 116 &&
      opcode != 120 && opcode != 88)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_sti(t_corewar *corewar,
			    t_process_list *current)
{
  int		temp;

  printf("COPY STI\n");
  temp = current->instruction.opcode;
  current->instruction.opcode = 124;
  copy_args(corewar, current);
  current->instruction.opcode = temp;
}

void		exec_op_sti(t_corewar	*corewar,
			    t_process_list	*current)
{
  int		value;
  int		nb1;
  int		nb2;
  int		pc;

  printf("EXEC STI\n");
  if (current->instruction.correct)
    {
      printf("CORRECT STI\n");
      value = current->process.reg[current->instruction.arg[0] - 1];
      if (current->instruction.type_arg[1] == 1)
	nb1 = current->process.reg[current->instruction.arg[1] - 1];
      else
	nb1 = current->instruction.arg[1];
      if (current->instruction.type_arg[2] == 1)
	nb2 = current->process.reg[current->instruction.arg[2] - 1];
      else
	nb2 = current->instruction.arg[2];
      pc = current->process.pc;
      if (current->instruction.type_arg[1] == 2)
	nb1 %= IDX_MOD;
      printf("SUR %d ad\n", (pc + nb1 + nb2) % MEM_SIZE);
      corewar->mem[(pc + nb1 + nb2 + 0) % MEM_SIZE] = value >> (8 * 3) & 255;
      corewar->mem[(pc + nb1 + nb2 + 1) % MEM_SIZE] = value >> (8 * 2) & 255;
      corewar->mem[(pc + nb1 + nb2 + 2) % MEM_SIZE] = value >> (8 * 1) & 255;
      corewar->mem[(pc + nb1 + nb2 + 3) % MEM_SIZE] = value >> (8 * 0) & 255;
    }
  current->process.pc = (current->process.pc + 7) % MEM_SIZE;
}
