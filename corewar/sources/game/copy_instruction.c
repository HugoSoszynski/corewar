/*
** copy_instruction.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 02:04:14 2016 corsin_a
** Last update Wed Mar 23 19:03:39 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"
#include	"op_list.h"

int		copy_instruction(t_corewar	*corewar,
				 t_process_list	*process_list)
{
  int		op;
  char		opcode;

  op = corewar->mem[process_list->process.pc];
  printf("op : %d\n", op);
  if (op < OP_LIVE || op > OP_AFF)
    {
      printf("\n");
      return (ERROR);
    }
  opcode = corewar->mem[(process_list->process.pc + 1) % MEM_SIZE];
  if (OP_TAB[op - 1].check(opcode) == SUCCESS)
    {
      process_list->instruction.op = op;
      process_list->instruction.opcode = opcode;
      OP_TAB[op - 1].copy(corewar, process_list);
      process_list->cycle = OP_TAB[op - 1].cycle;
      process_list->instruction.correct = true;
    }
  else
    {
      process_list->instruction.correct = false;
      process_list->cycle = OP_TAB[op - 1].cycle;
    }
  return (SUCCESS);
}
