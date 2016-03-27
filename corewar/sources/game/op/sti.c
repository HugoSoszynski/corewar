/*
** sti.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:21 2016 corsin_a
** Last update Sun Mar 27 13:59:23 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_sti(char	opcode)
{
  if (opcode != 84 && opcode != 100 && opcode != 104 && opcode != 116 &&
      opcode != 120 && opcode != 88)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_sti(t_corewar *corewar,
			    t_process_list *current)
{
  int		temp;

  temp = current->instruction.opcode;
  current->instruction.opcode = 124;
  copy_args(corewar, current);
  current->instruction.opcode = temp;
}

static void	set_args_to_exec(t_process_list *current,
				 int *nb1, int *nb2, int *value)
{
  int		r_nb;

  r_nb = REG_NUMBER;
  *value = current->process.reg[(current->instruction.arg[0] - 1) % r_nb];
  if (current->instruction.type_arg[1] == 1)
    *nb1 = current->process.reg[(current->instruction.arg[1] - 1) % r_nb];
  else
    *nb1 = current->instruction.arg[1];
  if (current->instruction.type_arg[2] == 1)
    *nb2 = current->process.reg[(current->instruction.arg[2] - 1) % r_nb];
  else
    *nb2 = current->instruction.arg[2];
}

void		exec_op_sti(t_corewar	*corewar,
			    t_process_list	*current)
{
  int		value;
  int		nb1;
  int		nb2;
  int		pc;

  if (current->instruction.correct)
    {
      set_args_to_exec(current, &nb1, &nb2, &value);
      pc = current->process.pc;
      /*if (current->instruction.type_arg[1] == 2)*/
	nb1 %= IDX_MOD;
      corewar->mem[(pc + nb1 + nb2 + 0) % MEM_SIZE] = value >> (8 * 3) & 255;
      corewar->mem[(pc + nb1 + nb2 + 1) % MEM_SIZE] = value >> (8 * 2) & 255;
      corewar->mem[(pc + nb1 + nb2 + 2) % MEM_SIZE] = value >> (8 * 1) & 255;
      corewar->mem[(pc + nb1 + nb2 + 3) % MEM_SIZE] = value >> (8 * 0) & 255;
    }
  current->process.pc = (current->process.pc + 7) % MEM_SIZE;
}
