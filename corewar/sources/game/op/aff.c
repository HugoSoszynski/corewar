/*
** aff.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:18 2016 corsin_a
** Last update Fri Mar 25 19:33:30 2016 Hugo SOSZYNSKI
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"corewar.h"

int		check_op_aff(char	opcode)
{
  printf("CHECK AFF\n");
  if (opcode != 64)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_aff(t_corewar *corewar,
			    t_process_list *current)
{
  printf("COPY AFF\n");
  copy_args(corewar, current);
}

void		exec_op_aff(t_corewar	*corewar,
			    t_process_list	*current)
{
  char		car;

  printf("EXEC AFF\n");
  (void)corewar;
  if (current->instruction.correct)
    {
      printf("CORRECT AFF\n");
      car = (char)(current->process.reg[current->instruction.arg[0] - 1] % 256);
      write(1, &car, sizeof(char));
    }
  move_pc(current);
}
