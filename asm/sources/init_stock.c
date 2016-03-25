/*
** init_stock.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Wed Mar 23 11:21:21 2016 Grégoire Loens
** Last update Fri Mar 25 17:28:39 2016 
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
  stock_cmd->type = 0;
  stock_cmd->line = NULL;
  stock_cmd->nbr_line = 0;
  stock_cmd->opcode = 0;
  stock_cmd->dot_code_octet = 0;
  stock_cmd->arg[0] = 0;
  stock_cmd->arg[1] = 0;
  stock_cmd->arg[3] = 0;
  stock_cmd->head = stock_cmd;
  stock_cmd->def = init_pile();
  stock_cmd->call = init_pile();
  stock_cmd->next = NULL;
  return (stock_cmd);
}

static void	init_cmd_node(void *_cmd)
{
  unsigned int	cpt;
  char		*cmd;

  cmd = _cmd;
  cpt = 0;
  while (cpt < sizeof(t_cmd))
    {
      cmd[cpt] = 0;
      cpt++;
    }
}

t_cmd		*add_cmd(t_cmd *stock_cmd)
{
  t_cmd		*new;

  if ((new = malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  init_cmd_node(new);
  new->next = NULL;
  new->head = stock_cmd->head;
  stock_cmd->next = new;
  return (new);
}
