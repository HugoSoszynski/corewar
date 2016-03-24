/*
** stock_pile.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/pile/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Wed Mar 23 01:30:46 2016 Grégoire Loens
** Last update Fri Mar 25 01:18:57 2016 
*/

#include	<stdlib.h>
#include	<stddef.h>
#include	"../../includes/pile_label.h"

t_pile		*init_pile(void)
{
  t_pile	*label;

  if ((label = malloc(sizeof(t_pile))) == NULL)
    return (NULL);
  label->nb_octet = 0;
  label->next = NULL;
  label->label_name = NULL;
  return (label);
}

t_pile		*add_label(t_pile *label)
{
  t_pile	*new_label;

  if ((new_label = init_pile()) == NULL)
    return (NULL);
  while (label->next != NULL)
    label = label->next;
  label->next = new_label;
  label->next->label_name = NULL;
  return (label);
}

t_pile		*stock_pile_for_def(t_pile *def, char *label, int line)
{
  t_pile	*head;
  int		cpt;

  cpt = my_strlen(cpt) - 1;
  head = def;
  while (def->next != NULL)
    def = def->next;
  if (def->label_name != NULL)
    {
      if ((def = add_label(def)) == NULL)
	return (NULL);
      def = def->next;
    }
  if (label[cpt] == ':')
    label[cpt] = '\0';
  def->label_name = label;
  def->nbr_line = line;
  def = head;
  return (head);
}
