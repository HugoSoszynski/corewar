/*
** aff.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:18 2016 corsin_a
** Last update Thu Mar 24 14:18:04 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

int		check_op_aff(char	opcode)
{
  printf("AFF\n");
  if (opcode != 64)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_aff(t_corewar *corewar,
			    t_process_list *current)
{

}

void		exec_op_aff(t_corewar	*corewar,
			    t_process_list	*current)
{

}
