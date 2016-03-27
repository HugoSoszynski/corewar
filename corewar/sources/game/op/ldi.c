/*
** ldi.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:15:43 2016 corsin_a
** Last update Sun Mar 27 21:45:57 2016 Hugo SOSZYNSKI
*/

#include	"corewar.h"

int		check_op_ldi(unsigned char	opcode)
{
  if (opcode != 84 && opcode != 148 && opcode != 164 && opcode != 212 &&
      opcode != 228 && opcode != 100)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_ldi(t_corewar *corewar,
			    t_process_list *current)
{
  int		temp;

  temp = current->instruction.opcode;
  current->instruction.opcode = 244;
  copy_args(corewar, current);
  current->instruction.opcode = temp;
  check_reg(current);
}

static int	get_nb(t_corewar		*corewar,
		       t_process_list		*current,
		       int			pt)
{
  int		nb;
  int		cpt;

  cpt = 0;
  nb = 0;
  while (cpt < 4)
    {
      nb = nb << 8;
      nb += corewar->mem[verif_pc(current->process.pc + cpt + pt)];
      ++cpt;
    }
  if (!IS_LIT_ENDIAN)
    my_reverse_bytes(&nb, sizeof(int));
  return (nb);
}

void		exec_op_ldi(t_corewar	*corewar,
			    t_process_list	*current)
{
  int		nb1;
  int		nb2;

  if (current->instruction.correct)
    {
      if (current->instruction.type_arg[0] == 1)
	nb1 = current->process.reg[current->instruction.arg[0] - 1];
      else
	nb1 = current->instruction.arg[0];
      if (current->instruction.type_arg[0] == 2)
	nb1 %= IDX_MOD;
      if (current->instruction.type_arg[1] == 1)
	nb2 = current->process.reg[current->instruction.arg[1] - 1];
      else
	nb2 = current->instruction.arg[1];
      current->process.reg[current->instruction.arg[2] - 1]
      = get_nb(corewar, current, (nb1 + nb2));
    }
  current->process.carry = (char)current->instruction.correct;
  current->process.pc = (current->process.pc + 7) % MEM_SIZE;
}
