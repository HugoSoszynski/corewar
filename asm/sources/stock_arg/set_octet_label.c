/*
** set_octet_label.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/stock_arg/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Thu Mar 24 21:41:06 2016 Grégoire Loens
** Last update Fri Mar 25 17:45:27 2016 
*/

#include	<unistd.h>
#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"pile_label.h"



#include	<stdio.h>


int		calc_octet(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  int		nb_octet;

  nb_octet = 0;
  if (call->call != NULL && def->def != NULL && call->call->nb_line > def->def->nb_line)
    nb_octet = calc_with_def(call, def, arg);
  else if (call-> call != NULL && def->def != NULL && call->call->nb_line < def->def->nb_line)
    nb_octet = calc_with_call(call, def, arg);
  return (nb_octet);
}

void		search_def(t_cmd *call, t_cmd *def)
{
  while(call->call != NULL && def->def != NULL && strcmpend(call->call->label_name, def->def->label_name) != 0)
    def->def = def->def->next;
}

void		set_arg(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  int		rpr;
  int		nbr_octet;

  rpr = -1;
  nbr_octet = calc_octet(call, def, arg);
  while (arg != NULL && call->call != NULL && arg->nbr_line != call->call->nb_line)
    arg = arg->next;
  /*  printf("%s , %c %c %c, %d %d %d \n", arg->line, arg->type_arg[0], arg->type_arg[1], arg->type_arg[2], arg->arg[0], arg->arg[1], arg->arg[2]);*/ 
  while (arg != NULL && arg->type_arg != NULL && (++rpr < 3))
    {
      if (arg->type_arg[rpr] == 12 && arg->arg[rpr] == 0)
	{
	  arg->arg[rpr] = nbr_octet;
	  return ;
	}
      else if (arg->type_arg[rpr] == 14 && arg->arg[rpr] == 0)
	{
	  arg->arg[rpr] = nbr_octet;
	  return ;
	}
    }
}

t_cmd		*set_octet_label(t_cmd *cmd)
{
  t_cmd		*call;
  t_cmd		*def;
  t_cmd		*arg;

  if (cmd != NULL && cmd->head != NULL)
    {
      call = cmd->head;
      def  = cmd->head;
      arg = cmd->head;
    }
  while(call != NULL)
    {
      search_def(call, def);
      set_arg(call, def, arg);
      def = cmd->head;
      arg = cmd->head;
      call = call->next;
    }
  return (cmd);
}
