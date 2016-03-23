/*
** prepare_corewar.c for corewar in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/preparation/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Tue Mar 22 15:44:55 2016 corsin_a
** Last update Tue Mar 22 23:37:11 2016 corsin_a
*/

#include		<stddef.h>
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
  process_list->cycle = 0;
  process_list->current.opcode = 0;
  process_list->process.carry = 0;
  process_list->process.pc = champion->address;
  process_list->process.nb_champion = champion->nb_champion;
  cpt = -1;
  while (++cpt < REG_NUMBER)
    my_init_tab(process_list->process.reg[cpt], REG_SIZE);
  *((int *)(process_list->process.reg[0])) = process_list->process.nb_champion;
  process_list->next = NULL;
  return (process_list);
}

static int		prepare_process_list(t_corewar		*corewar)
{
  int			cpt;
  t_process_list	*tmp;
  t_process_list	*process_list;

  cpt = 1;
  if ((process_list = create_process_list(&corewar->champion[cpt])) == NULL)
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

static void		prepare_mem(t_corewar			*corewar)
{
  int			cpt;
  int			cpt_prog;

  my_init_tab(corewar->mem, MEM_SIZE);
  cpt = 0;
  while (cpt < corewar->nb_champions)
    {
      cpt_prog = 0;
      while (cpt_prog < corewar->champion[cpt].header.prog_size)
	{
	  corewar->mem[(cpt_prog + corewar->champion[cpt].address) % MEM_SIZE]
	  = corewar->champion[cpt].prog[cpt_prog];
	  ++cpt_prog;
	}
      ++cpt;
    }
}

int			prepare_corewar(t_corewar		*corewar)
{
  corewar->cycle_to_die = CYCLE_TO_DIE;
  corewar->actual_cycle = 1;
  corewar->live_nb = 0;
  corewar->cycle_passed = 0;
  if (prepare_process_list(corewar) != SUCCESS)
    return (ERROR);
  prepare_mem(corewar);
  return (SUCCESS);
}
