/*
** sub.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:24 2016 corsin_a
** Last update Sun Mar 27 12:21:02 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_sub(char	opcode)
{
  if (opcode != 84)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_sub(t_corewar *corewar,
			    t_process_list *current)
{
  copy_args(corewar, current);
  check_reg(current);
}

void		exec_op_sub(t_corewar	*corewar,
			    t_process_list	*current)
{
  int		nb1;
  int		nb2;
  int		*reg;

  (void)corewar;
  if (current->instruction.arg[0] <= 0 ||
      current->instruction.arg[0] > REG_NUMBER ||
      current->instruction.arg[1] <= 0 ||
      current->instruction.arg[1] > REG_NUMBER ||
      current->instruction.arg[2] <= 0 ||
      current->instruction.arg[2] > REG_NUMBER)
    {
      current->process.carry = 0;
      move_pc(current);
      return ;
    }
  if (current->instruction.correct)
    {
      nb1 = current->process.reg[current->instruction.arg[0] - 1];
      nb2 = current->process.reg[current->instruction.arg[1] - 1];
      reg = &current->process.reg[current->instruction.arg[2] - 1];
      *reg = nb1 - nb2;
    }
  current->process.carry = (char)current->instruction.correct;
  move_pc(current);
}
