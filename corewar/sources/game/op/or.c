/*
** or.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:11 2016 corsin_a
** Last update Wed Mar 23 10:51:40 2016 corsin_a
*/

#include	"corewar.h"

int		check_op_or(char	opcode)
{
  if (opcode != 84 && opcode != 100 && opcode != 116 && opcode != 148 &&
      opcode != 164 && opcode != 180 && opcode != 212 && opcode != 228 &&
      opcode != 244)
    return (ERROR);
  return (SUCCESS);
}

void		op_or(t_corewar		*corewar,
		      t_process_list	*process_list)
{

}
