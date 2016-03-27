/*
** init_instruction.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 16:29:54 2016 corsin_a
** Last update Sun Mar 27 16:51:55 2016 corsin_a
*/

#include	"corewar.h"

static int	copy_one_arg(t_corewar		*corewar,
			     t_process_list	*process_list,
			     int		*ptr,
			     int		type)
{
  int		cpt;
  int		value;

  cpt = 0;
  value = 0;
  while (cpt < type)
    {
      if (type == 2)
	value = (short)(value << 8);
      else
    	value = value << 8;
      value += corewar->mem[verif_pc(process_list->process.pc + *ptr)];
      ++*ptr;
      ++cpt;
    }
  if (!IS_LIT_ENDIAN)
    my_reverse_bytes(&value, sizeof(type));
  return (value);
}

void		copy_args(t_corewar		*corewar,
			  t_process_list	*process_list)
{
  int		cpt;
  char		type;
  int		ptr;

  cpt = 0;
  ptr = 2;
  while (cpt < 3)
    {
      if ((type = process_list->instruction.opcode >> (6 - cpt * 2) & 3) > 0)
	{
	  if (type == 2) type = 4;
	  else if (type == 3) type = 2;
	  process_list->instruction.arg[cpt] =
	  copy_one_arg(corewar, process_list, &ptr, type);
	  process_list->instruction.type_arg[cpt] = type;
	}
      else
	return ;
      ++cpt;
    }
}
