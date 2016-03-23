/*
** except_op.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 14:52:15 2016 corsin_a
** Last update Wed Mar 23 15:11:31 2016 corsin_a
*/

#include	<stdio.h>
#include	"corewar.h"

void		except_sti(t_corewar		*corewar,
			   t_process_list	*process_list)
{
  printf("STI EXCEPT\n");
}

void		except_live(t_corewar		*corewar,
			    t_process_list	*process_list)
{
  int		cpt;

  printf("LIVE EXCEPT\n");
  cpt = 0;
  process_list->instruction.arg[0] = 0;
  while (cpt < 4)
    {
      process_list->instruction.arg[0] = process_list->instruction.arg[0] << 8;
      process_list->instruction.arg[0] +=
      corewar->mem[(process_list->process.pc + cpt) % MEM_SIZE];
      ++cpt;
    }
  if (!IS_LIT_ENDIAN)
    my_reverse_bytes(&process_list->instruction.arg[0], sizeof(int));
  process_list->instruction.opcode = 0;
  process_list->instruction.correct = false;
  process_list->cycle = ((t_op_tab*)(corewar->op_tab))[0].cycle;
}
