/*
** sti.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:21 2016 corsin_a
** Last update Wed Mar 23 16:30:44 2016 corsin_a
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
  current->instruction.opcode = 104;
  copy_args(corewar, current);
}

void		exec_op_sti(t_corewar	*corewar,
			    t_process_list	*current)
{

}
