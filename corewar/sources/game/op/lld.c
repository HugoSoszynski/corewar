/*
** lld.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:03 2016 corsin_a
** Last update Sun Mar 27 14:31:36 2016 corsin_a
*/

#include	"corewar.h"

int		check_op_lld(unsigned char opcode)
{
  if (opcode != 144 && opcode != 208)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_lld(t_corewar *corewar,
			    t_process_list *current)
{
  copy_args(corewar, current);
  check_reg(current);
}

static int	get_other_nb(t_corewar		*corewar,
			     t_process_list	*current)
{
  int		pt;
  int		nb;
  int		cpt;

  pt = current->instruction.arg[0];
  cpt = 0;
  nb = 0;
  while (cpt < 4)
    {
      nb = nb << 8;
      nb += corewar->mem[(current->process.pc + cpt + pt) % MEM_SIZE];
      ++cpt;
    }
  if (!IS_LIT_ENDIAN)
    my_reverse_bytes(&nb, sizeof(int));
  return (nb);
}

void		exec_op_lld(t_corewar		*corewar,
			   t_process_list	*current)
{
  int		*reg;

  if (current->instruction.correct)
    {
      reg = &(current->process.reg[current->instruction.arg[1] - 1]);
      if (current->instruction.type_arg[0] == 1)
	*reg = current->process.reg[current->instruction.arg[0] - 1];
      else if (current->instruction.type_arg[0] == 4)
	*reg = current->instruction.arg[0];
      else
	*reg = get_other_nb(corewar, current);
    }
  current->process.carry = (char)current->instruction.correct;
  move_pc(current);
}
