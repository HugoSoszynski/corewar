/*
** prepare_corewar.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/preparation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Tue Mar 22 15:44:55 2016 corsin_a
** Last update Tue Mar 22 22:32:06 2016 Hugo SOSZYNSKI
*/

#include		<stddef.h>
#include		<stdlib.h>
#include		"corewar.h"

t_process_list		*create_process_list(t_champion		*champion)
{
  t_process_list	*process_list;
  int			cpt;

  process_list = malloc(sizeof(t_process_list));
  process_list->cycle = 0;
  process_list->current.opcode = 0;
  process_list->process.carry = 0;
  process_list->process.pc = champion->address;
  process_list->process.nb_champion = champion->nb_champion;
  cpt = -1;
  while (++cpt < REG_NUMBER)
    my_init_tab(process_list->process.reg[cpt], REG_SIZE);
  *((int)(reg[0])) = process_list->process.nb_champion;
  process_list->next = NULL;
  return (process_list);
}

int			prepare_corewar(t_corewar		*corewar)
{
  int			cpt;
  t_process_list	*process_list;
  t_process_list	*tmp;

  corewar->cycle_to_die = CYCLE_TO_DIE;
  corewar->actual_cycle = 0;
  corewar->live_nb = 0;
  cpt = 1;
  if ((process_list = create_process_list(&corewar->champion[cpt])) == NULL)
    return (ERROR);
  tmp = process_list;
  while (cpt < corewar->nb_champion)
    {
      if ((tmp->next = create_process_list(&corewar->champion[cpt])) == NULL)
	return (ERROR);
      corewar->champions_alive[cpt] = false;
      tmp = tmp->next;
      ++cpt;
    }
  corewar->t_process_list = process_list;
  return (SUCCESS);
}
