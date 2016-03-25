/*
** st.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:15 2016 corsin_a
** Last update Fri Mar 25 00:25:42 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_st(unsigned char opcode)
{
  printf("CHECK ST\n");
  if (opcode != 96 && opcode != 112)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_st(t_corewar *corewar,
			   t_process_list *current)
{
  printf("COPY ST\n");
  copy_args(corewar, current);
}

void		exec_op_st(t_corewar		*corewar,
			   t_process_list	*current)
{
  int		nb;
  int		pt;
  int		pc;

  printf("EXEC ST\n");
  if (current->instruction.correct)
    {
      printf("CORRECT ST\n");
      pc = current->process.pc;
      nb = current->process.reg[current->instruction.arg[0] - 1];
      if (current->instruction.type_arg[1] == 1)
	current->process.reg[current->instruction.arg[1] - 1] = nb;
      else
	{
	  pt = current->instruction.arg[1];
	  corewar->mem[(pc + (pt % IDX_MOD) + 0) % MEM_SIZE] =
	  nb >> (8 * 3) & 255;
	  corewar->mem[(pc + (pt % IDX_MOD) + 1) % MEM_SIZE] =
	  nb >> (8 * 2) & 255;
	  corewar->mem[(pc + (pt % IDX_MOD) + 2) % MEM_SIZE] =
	  nb >> (8 * 1) & 255;
	  corewar->mem[(pc + (pt % IDX_MOD) + 3) % MEM_SIZE] =
	  nb >> (8 * 0) & 255;
	}
    }
  move_pc(current);
}
