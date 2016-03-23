/*
** copy_instruction.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 02:04:14 2016 corsin_a
** Last update Wed Mar 23 04:42:27 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

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
  if ((((t_op_tab*)(corewar->op_tab))[process_list->instruction.op - 1]
       .check(opcode)) == SUCCESS)
    {
      process_list->cycle = (((t_op_tab*)(corewar->op_tab))
			     [process_list->instruction.op - 1].cycle_to_die;
      process_list->instruction.opcode = opcode;
      process_list->instruction.arg[0] = 0;
      process_list->instruction.arg[1] = 0;
      process_list->instruction.arg[2] = 0;
      process_list->instruction.type_arg[0] = 0;
      process_list->instruction.type_arg[1] = 0;
      process_list->instruction.type_arg[2] = 0;
      process_list->instruction.correct = true;
    }
  else
    process_list->instruction.correct = false;
  return (SUCCESS);
}
