/*
** copy_instruction.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 02:04:14 2016 corsin_a
** Last update Wed Mar 23 10:49:22 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

static void	copy_args(t_corewar		*corewar,
			  t_process_list	*process_list)
{
  char		type;
  char		opcode;

  opcode = process_list->instruction.opcode;
  if ((type = opcode >> 6 & 3) > 0)
    printf("%d\n", type);
  if ((type = opcode >> 4 & 3) > 0)
    printf("%d\n", type);
  else
    return ;
  if ((type = opcode >> 2 & 3) > 0)
    printf("%d\n", type);
}

int		copy_instruction(t_corewar	*corewar,
				 t_process_list	*process_list)
{
  char		opcode;

  opcode = corewar->mem[(process_list->process.pc + 1) % MEM_SIZE];
  process_list->instruction.op =
      corewar->mem[process_list->process.pc % MEM_SIZE];
  if (process_list->instruction.op < OP_LIVE ||
      process_list->instruction.op > OP_AFF)
    return (ERROR);
  printf("%d", process_list->instruction.op);
  printf(" -> %d\n", opcode);
  if ((((t_op_tab*)(corewar->op_tab))[process_list->instruction.op - 1]
       .check(opcode)) == SUCCESS)
    {
      process_list->cycle = ((t_op_tab*)(corewar->op_tab))
	  [process_list->instruction.op - 1].cycle;
      process_list->instruction.opcode = opcode;
      process_list->instruction.correct = true;
      copy_args(corewar, process_list);
    }
  else
    process_list->instruction.correct = false;
  return (SUCCESS);
}
