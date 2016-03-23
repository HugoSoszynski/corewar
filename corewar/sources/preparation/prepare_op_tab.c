/*
** prepare_op_tab.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/preparation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:46:58 2016 corsin_a
** Last update Wed Mar 23 10:39:54 2016 corsin_a
*/

#include	<stdlib.h>
#include	"corewar.h"

static void	init_tab2(t_op_tab		*op_tab)
{
  op_tab[8].check = &check_op_zjmp;
  op_tab[8].exec = &op_zjmp;
  op_tab[8].cycle = CYCLE_ZJMP;
  op_tab[9].check = &check_op_ldi;
  op_tab[9].exec = &op_ldi;
  op_tab[9].cycle = CYCLE_LDI;
  op_tab[10].check = &check_op_sti;
  op_tab[10].exec = &op_sti;
  op_tab[10].cycle = CYCLE_STI;
  op_tab[11].check = &check_op_fork;
  op_tab[11].exec = &op_fork;
  op_tab[11].cycle = CYCLE_FORK;
  op_tab[12].check = &check_op_lld;
  op_tab[12].exec = &op_lld;
  op_tab[12].cycle = CYCLE_LLD;
  op_tab[13].check = &check_op_lldi;
  op_tab[13].exec = &op_lldi;
  op_tab[13].cycle = CYCLE_LLDI;
  op_tab[14].check = &check_op_lfork;
  op_tab[14].exec = &op_lfork;
  op_tab[14].cycle = CYCLE_LFORK;
  op_tab[15].check = &check_op_aff;
  op_tab[15].exec = &op_aff;
  op_tab[15].cycle = CYCLE_AFF;
}

static void	init_tab(t_op_tab		*op_tab)
{
  op_tab[0].check = &check_op_live;
  op_tab[0].exec = &op_live;
  op_tab[0].cycle = CYCLE_LIVE;
  op_tab[1].check = &check_op_ld;
  op_tab[1].exec = &op_ld;
  op_tab[1].cycle = CYCLE_LD;
  op_tab[2].check = &check_op_st;
  op_tab[2].exec = &op_st;
  op_tab[2].cycle = CYCLE_ST;
  op_tab[3].check = &check_op_add;
  op_tab[3].exec = &op_add;
  op_tab[3].cycle = CYCLE_ADD;
  op_tab[4].check = &check_op_sub;
  op_tab[4].exec = &op_sub;
  op_tab[4].cycle = CYCLE_SUB;
  op_tab[5].check = &check_op_and;
  op_tab[5].exec = &op_and;
  op_tab[5].cycle = CYCLE_AND;
  op_tab[6].check = &check_op_or;
  op_tab[6].exec = &op_or;
  op_tab[6].cycle = CYCLE_OR;
  op_tab[7].check = &check_op_xor;
  op_tab[7].exec = &op_xor;
  op_tab[7].cycle = CYCLE_XOR;
  init_tab2(op_tab);
}

int		prepare_op_tab(t_corewar	*corewar)
{
  t_op_tab	*op_tab;

  if ((op_tab = malloc(sizeof(t_op_tab) * 16)) == NULL)
    return (error_message("Can\'t perform malloc"));
  init_tab(op_tab);
  corewar->op_tab = op_tab;
  return (SUCCESS);
}
