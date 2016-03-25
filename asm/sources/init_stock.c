/*
** init_stock.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Wed Mar 23 11:21:21 2016 Grégoire Loens
** Last update Fri Mar 25 04:41:05 2016 
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"pile_label.h"
#include	"asm.h"



#include	<unistd.h>

t_cmd		*init_first_cmd()
{
  t_cmd		*stock_cmd;

  if ((stock_cmd = malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  stock_cmd->head = stock_cmd;
  stock_cmd->def = init_pile();
  stock_cmd->call = init_pile();
  stock_cmd->next = NULL;
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

t_cmd		*add_cmd(t_cmd *stock_cmd)
{
  t_cmd		*new_stock_cmd;
  t_cmd		*tmp;

  new_stock_cmd = init_cmd();
  tmp = stock_cmd->head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_stock_cmd;
  return (stock_cmd);
}
