/*
** set_octet_label.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/stock_arg/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Thu Mar 24 21:41:06 2016 Grégoire Loens
** Last update Sun Mar 27 07:19:17 2016 
*/

#include	<unistd.h>
#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"pile_label.h"


#include	<stdio.h>

void		search_def(t_cmd *call, t_cmd *def)
{
  while(call->call != NULL && def->def != NULL && strcmpend(call->call->label_name, def->def->label_name) != 0)
    def->def = def->def->next;
}

void		set_arg(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  int		nb_octet;

  while (arg != NULL && arg->nbr_line < call->call->nb_line)
    arg = arg->next;
  if (call->call->nb_line < def->def->nb_line)
    nb_octet = calc_call(call, def, arg);
  else
    nb_octet = calc_def(call, def, arg);
  set_octet(arg, call, nb_octet); 

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
  while(call != NULL && call->call != NULL)
    {
      search_def(call, def);
      set_arg(call, def, arg);
      def = cmd->head;
      arg = cmd->head;
      call->call = call->call->next;
    }
  return (cmd);
}
