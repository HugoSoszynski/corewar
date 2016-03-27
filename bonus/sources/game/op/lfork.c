/*
** lfork.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:55 2016 corsin_a
** Last update Sun Mar 27 06:59:58 2016 corsin_a
*/

#include	"corewar.h"

int		check_op_lfork(char	opcode)
{
  (void)opcode;
  return (SUCCESS);
}

void		copy_op_lfork(t_corewar *corewar,
			      t_process_list *current)
{
  int		cpt;

  cpt = 0;
  current->instruction.arg[0] = 0;
  while (cpt < 2)
    {
      current->instruction.arg[0] = current->instruction.arg[0] << 8;
      current->instruction.arg[0] +=
      corewar->mem[(current->process.pc + cpt + 1) % MEM_SIZE];
      ++cpt;
    }
  if (!IS_LIT_ENDIAN)
    my_reverse_bytes(&current->instruction.arg[0], sizeof(int));
  current->instruction.opcode = 0;
  current->instruction.correct = false;
  current->cycle = ((t_op_tab*)(corewar->op_tab))[0].cycle;
}

void		exec_op_lfork(t_corewar	*corewar,
			      t_process_list	*current)
{
  (void)corewar;
  if (current->instruction.correct)
    {
      if (clone_process(current, current->instruction.arg[0]) != ERROR)
	current->process.carry = 1;
      ++corewar->champion[current->process.cpt].nb_process;
      corewar->mem_champ[(current->process.pc + current->instruction.arg[0]) % MEM_SIZE] =
      corewar->champion[current->process.cpt].color;
    }
  current->process.pc = (current->process.pc + 3) % MEM_SIZE;
}
