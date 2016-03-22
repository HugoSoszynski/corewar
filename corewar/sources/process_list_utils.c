/*
** process_list_utils.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/preparation/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 22 22:27:30 2016 Hugo SOSZYNSKI
** Last update Tue Mar 22 23:41:43 2016 Hugo SOSZYNSKI
*/

#include		<stddef.h>
#include		<stdlib.h>
#include		"corewar.h"

static void		cpy_t_process(t_process *src,
				      t_process *dest,
				      int add_to_pc)
{
  int			cpt;
  int			count;

  dest->carry = src->carry;
  dest->nb_champion = src->nb_champion;
  dest->pc = src->pc + add_to_pc;
  cpt = -1;
  while (++cpt < REG_NUMBER)
    {
      count = -1;
      while (++count < REG_SIZE)
	dest->reg[cpt][count] = src->[cpt][count];
    }
}

int			clone_process(t_process_list *src, int add_to_pc)
{
  t_process_list	*tmp;

  tmp = src;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if ((tmp->next = malloc(sizeof(t_process_list))) == NULL)
    return (error_message("Can't perform malloc"));
  tmp = tmp->next;
  tmp->cycle = 0;
  tmp->next = NULL;
  cpy_t_process(&(src->process), &(tmp->process), add_to_pc);
}

void			free_processlist(t_process_list *list)
{
  t_process_list	*tmp;

  while (list->next != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
  free(list);
}
