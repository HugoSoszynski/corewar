/*
** process_list_utils.c for corewar in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/corewar/sources/preparation/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 22 22:27:30 2016 Hugo SOSZYNSKI
** Last update Wed Mar 23 11:06:24 2016 Hugo SOSZYNSKI
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
    return (error_message("Can\'t perform malloc"));
  tmp = tmp->next;
  tmp->cycle = -1;
  tmp->next = NULL;
  cpy_t_process(&(src->process), &(tmp->process), add_to_pc);
  return (SUCCESS);
}

static void		check_zombie(t_process_list *head,
				     t_process_list *list,
				     t_process_list *tmp,
				     unsigned int nb_champion)
{
  if (head->process.nb_champion == nb_champion)
    {
      free(head);
      head = tmp;
      list = tmp;
    }
  else if (tmp->process.nb_champion == nb_champion)
    {
      list->next = tmp->next;
      free(tmp);
      list = list->next;
    }
}

t_process_list		*kill_zombies(t_process_list *list,
				      unsigned int nb_champion)
{
  t_process_list	*tmp;
  t_process_list	*head;

  head = list;
  while (list != NULL)
    {
      tmp = list->next;
      check_zombie(head, list, tmp, nb_champion);
    }
  if (head != NULL && head->next == NULL &&
      head->process.nb_champion == nb_champion)
    {
      free(head);
      return (NULL);
    }
  return (head);
}

void			free_processlist(t_process_list *list)
{
  t_process_list	*tmp;

  while (list != NULL && list->next != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
  free(list);
}
