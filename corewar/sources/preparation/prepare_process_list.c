/*
** prepare_process_list.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/preparation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Wed Mar 23 03:45:08 2016 corsin_a
** Last update Wed Mar 23 13:02:51 2016 Hugo SOSZYNSKI
*/


#include		<stdlib.h>

#include		"corewar.h"

static t_process_list	*create_process_list(t_champion		*champion)
{
  t_process_list	*process_list;
  int			cpt;

  if ((process_list = malloc(sizeof(t_process_list))) == NULL)
    {
      error_message("Can't perform malloc");
      return (NULL);
    }
  process_list->cycle = -1;
  process_list->instruction.opcode = 0;
  process_list->process.carry = 0;
  process_list->process.pc = champion->address;
  process_list->process.nb_champion = champion->nb_champion;
  cpt = -1;
  while (++cpt < REG_NUMBER)
    process_list->process.reg[cpt] = 0;
  process_list->process.reg[0] = process_list->process.nb_champion;
  process_list->next = NULL;
  return (process_list);
}

int			prepare_process_list(t_corewar		*corewar)
{
  int			cpt;
  t_process_list	*tmp;
  t_process_list	*process_list;

  cpt = 1;
  if ((process_list = create_process_list(&corewar->champion[0])) == NULL)
    return (ERROR);
  tmp = process_list;
  while (cpt < corewar->nb_champions)
    {
      if ((tmp->next = create_process_list(&corewar->champion[cpt])) == NULL)
	return (ERROR);
      corewar->champions_alive[cpt] = IS_RUN;
      tmp = tmp->next;
      ++cpt;
    }
  corewar->process_list = process_list;
  return (SUCCESS);
}
