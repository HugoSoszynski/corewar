/*
** init_stock.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Wed Mar 23 11:21:21 2016 Grégoire Loens
** Last update Fri Mar 25 00:05:10 2016 
*/

#include	<stdlib.h>
#include	"asm.h"

t_cmd		*init_first_cmd()
{
  t_list	*stock_cmd;

  if ((stock_cmd = malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  stock_cmd-> init_cmd();
  stock_cmd->head = stock_cmd;
  stock_cmd->head->def = init_pile();
  stock_cmd->head->call = init_pile();
  stock_cmd->head->next = NULL;
  return (stock_cmd);
}

t_cmd		*init_cmd()
{
  t_cmd		*stock_cmd;

  if ((stock_cmd = malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  stock_cmd->next = NULL;
  return (stock_cmd);
}

t_list		add_cmd(t_list *stock_cmd)
{
  t_cmd		*new_stock_cmd;

  new_stock_cmd = init_cmd();
  stock_cmd = stock_cmd->head->next;
  while (stock_cmd->next != NULL)
    stock_cmd = stock_cmd->next;
  stock_cmd->next = new_stock_cmd;
  return (stock_cmd);
}
