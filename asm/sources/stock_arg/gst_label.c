/*
** gst_label.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/stock_arg/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Thu Mar 24 16:56:13 2016 Grégoire Loens
** Last update Fri Mar 25 02:50:03 2016 
*/

#include	<stddef.h>
#include	"asm.h"
#include	"pile_label.h"
/*
t_cmd		*acr_label(t_cmd *stock_arg)
{
  t_cmd		*tmp;

  tmp = stock_arg->head;
 while (stock_arg->head->def->next != NULL)
    {
      tmp->def->nb_octet += sizeof(stock_arg->type_arg[1]);
      tmp->def->nb_octet += sizeof(stock_arg->type_arg[2]);
      tmp->def->nb_octet += sizeof(stock_arg->type_arg[3]);
      tmp->def = stock_arg->head->def->next;
    }
  return (stock_arg);
}
*/
/*
t_cmd		*set_octet(t_cmd *stock_arg)
{
  while (stock_arg->head->def->next != NULL)
    {
      if (arg_cmp(stock_arg->head->def->label, t_pile->call->label) == 1)
	stock_arg->head->call->nb_octet = stock->head->def->nb_octet;
      else
	stock_arg->head->def = stock_arg->head->def->next;
    }
  return (stock_arg);
}
*/
