/*
** ld.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:49 2016 corsin_a
** Last update Wed Mar 23 10:50:57 2016 corsin_a
*/

#include	"corewar.h"

int		check_op_ld(char	opcode)
{
  if (opcode != 144 && opcode != 208)
    return (ERROR);
  return (SUCCESS);
}

void		op_ld(t_corewar		*corewar,
		      t_process_list	*process_list)
{

}
