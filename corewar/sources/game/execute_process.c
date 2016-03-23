/*
** execute_process.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 01:13:18 2016 corsin_a
** Last update Wed Mar 23 04:19:04 2016 corsin_a
*/

#include	"corewar.h"

void		execute_process(t_corewar	*corewar)
{
  t_process_list *process_list;

  process_list = corewar->process_list;
  while (process_list != NULL)
    {
      if (process_list->cycle == -1)
	if (copy_instruction(corewar, process_list) != SUCCESS)
	    ++process_list->process.pc;
      process_list->cycle = 0;
      process_list = process_list->next;
    }
}
