/*
** lld.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:03 2016 corsin_a
** Last update Wed Mar 23 03:29:07 2016 corsin_a
*/

#include	"corewar.h"

int		check_op_lld(char	opcode)
{
  if (opcode != 144 || opcode != 208)
    return (ERROR);
  return (SUCCESS);
}

void		op_lld(t_corewar	*corewar,
		       t_process_list	*process_list)
{

}
