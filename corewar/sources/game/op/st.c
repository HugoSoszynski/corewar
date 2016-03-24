/*
** st.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:15 2016 corsin_a
** Last update Thu Mar 24 15:50:34 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_st(unsigned char opcode)
{
  printf("ST\n");
  if (opcode != 80 && opcode != 208)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_st(t_corewar *corewar,
			   t_process_list *current)
{
  copy_args(corewar, current);
}

void		exec_op_st(t_corewar		*corewar,
			   t_process_list	*current)
{
  int		nb;
  int		pt;
  int		pc;

  if (current->instruction.correct)
    {
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
