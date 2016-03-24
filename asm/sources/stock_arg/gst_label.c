/*
** gst_label.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/stock_arg/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Thu Mar 24 16:56:13 2016 Grégoire Loens
** Last update Thu Mar 24 17:14:19 2016 Grégoire Loens
*/

t_cmd		*acr_label(t_cmd *stock_arg)
{
 while (stock_arg->head->def->next != NULL)
    {
      stock_arg->head->def->nb_octet += sizeof(stock_arg->type_arg[1]);
      stock_arg->head->def->nb_octet += sizeof(stock_arg->type_arg[2]);
      stock_arg->head->def->nb_octet += sizeof(stock_arg->type_arg[3]);
      stock_arg->head->def = stock_arg->head->def->next;
    }
  return (stock_arg);
}
