/*
** st.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:15 2016 corsin_a
** Last update Wed Mar 23 16:47:05 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_st(char	opcode)
{
  if (opcode != 80 && opcode != 208)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_st(t_corewar *corewar,
			   t_process_list *current)
{

}

void		exec_op_st(t_corewar		*corewar,
			   t_process_list	*current)
{

}
