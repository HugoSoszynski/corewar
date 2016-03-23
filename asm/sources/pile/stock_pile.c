/*
** stock_pile.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/pile/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Wed Mar 23 01:30:46 2016 Grégoire Loens
** Last update Wed Mar 23 10:54:44 2016 Grégoire Loens
*/

#include	<stdlib.h>
#include	<stddef.h>
#include	"../../includes/pile_label.h"

t_pile		*init_pile(void)
{
  t_pile	*label;

  if ((label = malloc(sizeof(t_pile))) == NULL)
    return (NULL);
  label->next = NULL;
  label->label_name = NULL;
  return (label);
}

t_pile		*add_label(t_pile *label)
{
  t_pile	*new_label;

  new_label = init_pile();
  label->next = new_label;
  label->next->label_name = NULL;
  return (label);
}

t_pile		*stock_pile_for_def(t_pile *def, char *line)
{
  int		cpt;

  cpt = 0;
  while (def->next != NULL)
    def = def->next;
  if (def->label_name != NULL)
    {
      def = add_label(def);
      def = def->next;
    }
  while(line[cpt] != ':')
    cpt++;
  if ((def->label_name = malloc(sizeof(char) * cpt + 1)) == NULL)
    return (NULL);
  cpt = 0;
  while (line[cpt] != ':')
    {
      def->label_name[cpt] = line[cpt];
      cpt++;
    }
  return (def);
}

t_pile		*stock_pile_for_call(t_pile *call, char *arg)
{
  int		cpt;

  cpt = 0;
  while (arg[cpt] != 0)
   cpt++;
  while(call->next != NULL)
    call = call->next;
  if (call->label_name != NULL)
    {
      call = add_label(call);
      call = call->next;
    }
  if ((call->label_name = malloc(sizeof(char) * cpt + 1)) == NULL)
    return (NULL);
  cpt = 0;
  while (arg[cpt] != 0)
    {
      call->label_name[cpt] = arg[cpt];
      cpt++;
    }
  return (call);
}
