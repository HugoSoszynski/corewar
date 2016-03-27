/*
** aff.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:18 2016 corsin_a
** Last update Sun Mar 27 04:01:54 2016 corsin_a
*/

#include	<unistd.h>
#include	"corewar.h"

int		check_op_aff(char	opcode)
{
  if (opcode != 64)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_aff(t_corewar *corewar,
			    t_process_list *current)
{
  copy_args(corewar, current);
}

void		exec_op_aff(t_corewar	*corewar,
			    t_process_list	*current)
{
  char		car;
  int		tmp;

  (void)corewar;
  if (current->instruction.correct)
    {
      tmp = current->process.reg[current->instruction.arg[0] - 1];
      car = (char)(tmp % 256);
      write(1, &car, 1);
    }
  move_pc(current);
}
