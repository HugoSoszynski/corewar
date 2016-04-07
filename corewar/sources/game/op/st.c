/*
** st.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:15 2016 corsin_a
** Last update Mon Apr  4 21:25:41 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_st(unsigned char opcode)
{
  if (opcode != 80 && opcode != 112)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_st(t_corewar *corewar,
			   t_process_list *current)
{
  copy_args(corewar, current);
  check_reg(current);
}

void		exec_op_st(t_corewar		*corewar,
			   t_process_list	*current)
{
  int		nb;
  short		pt;
  int		pc;

  if (current->instruction.correct)
    {
      pc = current->process.pc;
      nb = current->process.reg[(current->instruction.arg[0] - 1) %
				REG_NUMBER];
      if (current->instruction.type_arg[1] == 1)
	current->process.reg[(current->instruction.arg[1] - 1) %
			     REG_NUMBER] = nb;
      else
	{
	  pt = (short)current->instruction.arg[1];
          pt %= IDX_MOD;
	  corewar->mem[verif_pc(pc + pt + 0)] = nb >> (8 * 3) & 255;
	  corewar->mem[verif_pc(pc + pt + 1)] = nb >> (8 * 2) & 255;
	  corewar->mem[verif_pc(pc + pt + 2)] = nb >> (8 * 1) & 255;
	  corewar->mem[verif_pc(pc + pt + 3)] = nb >> (8 * 0) & 255;
	}
    }
  move_pc(current);
}
