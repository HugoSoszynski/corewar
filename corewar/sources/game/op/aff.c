/*
** aff.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:18 2016 corsin_a
** Last update Sat Mar 26 18:02:28 2016 Hugo SOSZYNSKI
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

  (void)corewar;
  if (current->instruction.correct)
    {
      car = (char)(current->process.reg[current->instruction.arg[0] - 1] % 256);
      write(1, &car, sizeof(char));
    }
  move_pc(current);
}
