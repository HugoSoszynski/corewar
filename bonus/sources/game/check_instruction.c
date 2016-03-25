/*
** copy_instruction.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 02:04:14 2016 corsin_a
** Last update Fri Mar 25 12:11:14 2016 Hugo SOSZYNSKI
*/

#include	<stdio.h>
#include	"corewar.h"
#include	"op_list.h"

int		check_instruction(t_corewar	*corewar,
				  t_process_list	*process_list)
{
  int		op;
  char		opcode;

  my_init_tab(&(process_list->instruction), sizeof(t_instruction));
  op = corewar->mem[process_list->process.pc];
  process_list->instruction.op = op;
  printf("op : %d\n", op);
  if (op < OP_LIVE || op > OP_AFF)
    {
      printf("\n");
      return (ERROR);
    }
  opcode = corewar->mem[(process_list->process.pc + 1) % MEM_SIZE];
  if (OP_TAB[op - 1].check(opcode) == SUCCESS)
    {
      printf("COPY\n");
      process_list->instruction.opcode = opcode;
      OP_TAB[op - 1].copy(corewar, process_list);
      process_list->instruction.correct = true;
    }
  else
    process_list->instruction.correct = false;
  process_list->cycle = OP_TAB[op - 1].cycle;
  return (SUCCESS);
}
