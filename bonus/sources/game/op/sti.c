/*
** sti.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/op/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:16:21 2016 corsin_a
** Last update Sun Mar 27 15:41:15 2016 corsin_a
*/

#include	"corewar.h"

int		check_op_sti(char	opcode)
{
  if (opcode != 84 && opcode != 100 && opcode != 104 && opcode != 116 &&
      opcode != 120 && opcode != 88)
    return (ERROR);
  return (SUCCESS);
}

void		copy_op_sti(t_corewar *corewar,
			    t_process_list *current)
{
  int		temp;

  temp = current->instruction.opcode;
  current->instruction.opcode = 124;
  copy_args(corewar, current);
  current->instruction.opcode = temp;
  check_reg(current);
}

void		exec_op_sti(t_corewar	*corewar,
			    t_process_list	*current)
{
  int		value;
  short		nb1;
  short		nb2;
  int		pc;

  if (current->instruction.correct)
    {
      value = current->process.reg[current->instruction.arg[0] - 1];
      if (current->instruction.type_arg[1] == 1)
	nb1 = (short)current->process.reg[current->instruction.arg[1] - 1];
      else
	nb1 = (short)current->instruction.arg[1];
      if (current->instruction.type_arg[2] == 1)
	nb2 = (short)current->process.reg[current->instruction.arg[2] - 1];
      else
	nb2 = (short)current->instruction.arg[2];
      pc = current->process.pc;
      if (current->instruction.type_arg[1] == 2)
	nb1 %= IDX_MOD;
      corewar->mem[verif_pc(pc + nb1 + nb2 + 0)] = value >> (8 * 3) & 255;
      corewar->mem[verif_pc(pc + nb1 + nb2 + 1)] = value >> (8 * 2) & 255;
      corewar->mem[verif_pc(pc + nb1 + nb2 + 2)] = value >> (8 * 1) & 255;
      corewar->mem[verif_pc(pc + nb1 + nb2 + 3)] = value >> (8 * 0) & 255;
      corewar->mem_champ[verif_pc(pc + nb1 + nb2 + 0)] =
      corewar->champion[current->process.cpt].color;
      corewar->mem_champ[verif_pc(pc + nb1 + nb2 + 1)] =
      corewar->champion[current->process.cpt].color;
      corewar->mem_champ[verif_pc(pc + nb1 + nb2 + 2)] =
      corewar->champion[current->process.cpt].color;
      corewar->mem_champ[verif_pc(pc + nb1 + nb2 + 3)] =
      corewar->champion[current->process.cpt].color;
    }
  current->process.pc = (current->process.pc + 7) % MEM_SIZE;
}
