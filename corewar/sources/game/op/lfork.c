/*
** lfork.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:55 2016 corsin_a
** Last update Wed Mar 23 03:29:35 2016 corsin_a
*/

#include	"corewar.h"

int		check_op_lfork(char	opcode)
{
  if (opcode != 128)
    return (ERROR);
  return (SUCCESS);
}

void		op_lfork(t_corewar	*corewar,
			 t_process_list	*process_list)
{

}
