/*
** fork.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:32 2016 corsin_a
** Last update Wed Mar 23 03:29:40 2016 corsin_a
*/

#include	"corewar.h"

int		check_op_fork(char	opcode)
{
  if (opcode != 128)
    return (ERROR);
  return (SUCCESS);
}

void		op_fork(t_corewar	*corewar,
			t_process_list	*process_list)
{

}
