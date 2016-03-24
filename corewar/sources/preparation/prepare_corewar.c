/*
** prepare_corewar.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/preparation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Tue Mar 22 15:44:55 2016 corsin_a
** Last update Thu Mar 24 13:24:53 2016 corsin_a
*/

#include		"corewar.h"

int			prepare_corewar(t_corewar		*corewar)
{
  int			cpt;

  cpt = 0;
  while (cpt < corewar->nb_champions)
    {
      corewar->champions_alive[cpt] = IS_RUN;
      ++cpt;
    }
  corewar->cycle_to_die = CYCLE_TO_DIE;
  corewar->actual_cycle = 1;
  corewar->live_nb = 0;
  corewar->cycle_passed = 0;
  if (prepare_process_list(corewar) != SUCCESS)
    return (ERROR);
  prepare_mem(corewar);
  if (prepare_op_tab(corewar) != SUCCESS)
    return (ERROR);
  return (SUCCESS);
}
