/*
** stock_pile.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/pile/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Wed Mar 23 01:30:46 2016 Grégoire Loens
** Last update Fri Mar 25 14:33:11 2016 
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"pile_label.h"


#include	<stdio.h>


t_pile		*init_pile(void)
{
  t_pile	*label;

  if ((label = malloc(sizeof(t_pile))) == NULL)
    return (NULL);
  label->nb_line = 0;
  label->nb_octet = 0;
  label->next = NULL;
  label->label_name = NULL;
  return (label);
}

t_pile		*add_label(t_pile *label)
{
  t_pile	*new_label;
  t_pile	*tmp;

  tmp = label;
  if ((new_label = init_pile()) == NULL)
    return (NULL);
  /*  while (tmp->next != NULL)
      tmp = tmp->next;*/
  tmp->next = new_label;
  tmp->next->label_name = NULL;
  tmp->next->next = NULL;
  return (label);
}

t_pile		*stock_pile_for_call(t_pile *call, char *label, int line)
{
  t_pile	*head;

  head = call;
  while (head->next != NULL)
    head = head->next;
  if (head->label_name != NULL)
    {
      if ((head = add_label(head)) == NULL)
	return (NULL);
      head = head->next;
    }
  head->label_name = label;
  head->nb_line = line;
  return (call);
  
}

t_pile		*stock_pile_for_def(t_pile *def, char *label, int line)
{
  t_pile	*head;
  int		cpt;

  cpt = 0;
  head = def;
  while (head->next != NULL)
    head = head->next;
  if (head->label_name != NULL)
    {
      if ((head = add_label(def)) == NULL)
	return (NULL);
      head = head->next;
    }
  head->label_name = label;
  while (head->label_name[cpt] != ':')
    cpt++;
  while (head->label_name[cpt] != '\0')
    {
      head->label_name[cpt] = '\0';
      cpt++;
    }
  head->nb_line = line;
  return (def);
}
