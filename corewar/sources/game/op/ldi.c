/*
** ldi.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:43 2016 corsin_a
** Last update Wed Mar 23 16:45:20 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_ldi(char	opcode)
{
  if (opcode != 84 && opcode != 148 && opcode != 164 && opcode != 212 &&
      opcode != 228 && opcode != 100)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_ldi(t_corewar *corewar,
			    t_process_list *current)
{

}

void		exec_op_ldi(t_corewar	*corewar,
			    t_process_list	*current)
{

}