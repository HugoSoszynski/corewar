/*
** set_octet_label.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/stock_arg/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Thu Mar 24 21:41:06 2016 Grégoire Loens
** Last update Fri Mar 25 01:57:47 2016 
*/

#include	<unistd.h>
#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"pile_label.h"

int		calc_octet(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  int		nb_octet;

  nb_octet = 0;
  if (call->call->nb_line > def->def->nb_line && call->call != NULL
      && def->def != NULL)
    nb_octet = calc_with_def(call, def, arg);
  else if (call->call->nb_line < def->def->nb_line && call->call != NULL
	   && def->def != NULL)
    nb_octet = calc_with_call(call, def, arg);
  return (nb_octet);
}

void		search_def(t_cmd *call, t_cmd *def)
{
  while(strcmpend(call->call->label, def->def->label) != 1)
    def->def = def->def->next;
}

void		set_arg(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  int		rpr;
  int		nb_octet;

  rpr = -1;
  nb_octet = calc_octet(call, def, arg);
  while (arg->nb_line != call->call->nb_line && arg != NULL
	 && call->call != NULL)
    arg = arg->next;
  while (arg->type_arg[++rpr] != 0)
    {
      if (arg->type_arg[rpr] == 12 && arg->arg[rpr] == 0)
	{
	  arg->arg[rpr] = nb_octet;
	  arg->type_arg[rpr] = 2;
	  return ;
	}
      else if (arg->type_arg[rpr] == 14 && arg->arg[rpr] == 0)
	{
	  arg->arg[rpr] = nbr_octet;
	  arg->type_arg[rpr] = 4;
	  return ;
	}
    }
}

t_cmd		set_octet_label(t_cmd *cmd)
{
  t_cmd		*call;
  t_cmd		*def;
  t_cmd		*arg;

  call = cmd->head;
  def  = cmd->head;
  arg = cmd->head;
  while(call->call != NULL);
    {
      search_def(call, def);
      set_arg(call, def, arg);
      def = cmd->head;
      arg = cmd->head;
      call->call->next;
    }
}
