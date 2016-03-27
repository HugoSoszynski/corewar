/*
** st.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:15 2016 corsin_a
** Last update Sun Mar 27 12:05:49 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_st(unsigned char opcode)
{
  if (opcode != 96 && opcode != 112)
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
  int		r_nb;

  r_nb = REG_NUMBER;
  if (current->instruction.correct)
    {
      nb = current->process.reg[(current->instruction.arg[0] - 1) % r_nb];
      if (current->instruction.type_arg[1] == 1)
	current->process.reg[(current->instruction.arg[1] - 1) % r_nb] = nb;
      else
	{
	  pt = current->instruction.arg[1];
	  corewar->mem[(current->process.pc + (pt % IDX_MOD) + 0) % MEM_SIZE] =
	  nb >> (8 * 3) & 255;
	  corewar->mem[(current->process.pc + (pt % IDX_MOD) + 1) % MEM_SIZE] =
	  nb >> (8 * 2) & 255;
	  corewar->mem[(current->process.pc + (pt % IDX_MOD) + 2) % MEM_SIZE] =
	  nb >> (8 * 1) & 255;
	  corewar->mem[(current->process.pc + (pt % IDX_MOD) + 3) % MEM_SIZE] =
	  nb >> (8 * 0) & 255;
	}
    }
  move_pc(current);
}
