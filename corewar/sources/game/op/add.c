/*
** add.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 01:55:26 2016 corsin_a
** Last update Wed Mar 23 16:41:21 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_add(char	opcode)
{
  if (opcode != 84)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_add(t_corewar *corewar,
			    t_process_list *current)
{
  
}

void		exec_op_add(t_corewar	*corewar,
			    t_process_list	*current)
{

}
