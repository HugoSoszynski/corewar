/*
** execute_process.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 01:13:18 2016 corsin_a
** Last update Thu Mar 24 17:19:41 2016 corsin_a
*/

#include	<stdio.h>
#include	"op_list.h"
#include	"corewar.h"

void		move_pc(t_process_list		*process_list)
{
  int		type;

  if (process_list->instruction.correct == false)
    {
      ++process_list->process.pc;
      return ;
    }
  process_list->process.pc = (process_list->process.pc + 2) % MEM_SIZE;
  if ((type = process_list->instruction.type_arg[0]) != 0)
    process_list->process.pc = (process_list->process.pc + type) % MEM_SIZE;
  else
    return ;
  if ((type = process_list->instruction.type_arg[1]) != 0)
    process_list->process.pc = (process_list->process.pc + type) % MEM_SIZE;
  else
    return ;
  if ((type = process_list->instruction.type_arg[2]) != 0)
    process_list->process.pc = (process_list->process.pc + type) % MEM_SIZE;
}

void		execute_process(t_corewar	*corewar)
{
  t_process_list *process_list;

  process_list = corewar->process_list;
  while (process_list != NULL)
    {
      printf("champ %d ===> pc %d\n", process_list->process.nb_champion, process_list->process.pc);
      if (process_list->cycle == -1 &&
	  copy_instruction(corewar, process_list) != SUCCESS)
	++process_list->process.pc;
      if (process_list->cycle > 0)
	--process_list->cycle;
      else if (process_list->cycle == 0)
	{
	  /*if (process_list->instruction.op >= OP_LIVE &&
		process_list->instruction.op <= OP_AFF)*/
	    OP_TAB[process_list->instruction.op - 1].exec(corewar, process_list);
	  process_list->cycle = -1;
	}
      process_list = process_list->next;
    }
}
