/*
** copy_instruction.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/game/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 02:04:14 2016 corsin_a
** Last update Wed Mar 23 11:56:26 2016 corsin_a
*/

#include	<stdio.h>
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
      value = value << 8;
      value += corewar->mem[(process_list->process.pc + *ptr) % MEM_SIZE];
      if (!IS_LIT_ENDIAN)
	my_reverse_bytes(&value, sizeof(int));
      ++*ptr;
      ++cpt;
    }
  return (value);
}

static void	copy_args(t_corewar		*corewar,
			  t_process_list	*process_list)
{
  char		type;
  int		ptr;

  ptr = 2;
  if ((type = process_list->instruction.opcode >> 6 & 3) > 0)
    {
      process_list->instruction.arg[0] =
      copy_one_arg(corewar, process_list, &ptr, type);
      process_list->instruction.type_arg[0] = type;
      printf("%d : %d\n",
	     process_list->instruction.arg[0],
	     process_list->instruction.type_arg[0]);
    }
  if ((type = process_list->instruction.opcode >> 4 & 3) > 0)
    {
      process_list->instruction.arg[1] =
      copy_one_arg(corewar, process_list, &ptr, type);
      process_list->instruction.type_arg[1] = type;
      printf("%d : %d\n",
	     process_list->instruction.arg[1],
	     process_list->instruction.type_arg[1]);
    }
  else
    return ;
  if ((type = process_list->instruction.opcode >> 2 & 3) > 0)
    {
      process_list->instruction.arg[2] =
      copy_one_arg(corewar, process_list, &ptr, type);
      process_list->instruction.type_arg[2] = type;
      printf("%d : %d\n",
	     process_list->instruction.arg[2],
	     process_list->instruction.type_arg[2]);
    }
}

int		copy_instruction(t_corewar	*corewar,
				 t_process_list	*process_list)
{
  char		opcode;

  opcode = corewar->mem[(process_list->process.pc + 1) % MEM_SIZE];
  process_list->instruction.op =
      corewar->mem[process_list->process.pc % MEM_SIZE];
  printf("op : %d\n", process_list->instruction.op);
  if (process_list->instruction.op < OP_LIVE ||
      process_list->instruction.op > OP_AFF)
    return (ERROR);
  printf("%d", process_list->instruction.op);
  printf(" -> %d\n", opcode);
  if ((((t_op_tab*)(corewar->op_tab))[process_list->instruction.op - 1]
       .check(opcode)) == SUCCESS)
    {
      process_list->instruction.opcode = opcode;
      process_list->instruction.correct = false;
      copy_args(corewar, process_list);
    }
  else
    process_list->instruction.correct = false;
  process_list->cycle = ((t_op_tab*)(corewar->op_tab))
      [process_list->instruction.op - 1].cycle;
  return (SUCCESS);
}
