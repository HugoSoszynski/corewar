/*
** calc_octet.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/stock_arg/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Thu Mar 24 23:20:29 2016 Grégoire Loens
** Last update Fri Mar 25 01:45:24 2016 
*/

#include	<stddef.h>
#include	"asm.h"
#include	"pile_label.h"

int		calc_with_def(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  while (arg->nb_line != def->def->nb_line && arg != NULL && def->def != NULL)
    arg = arg->next;
  while (arg->nb_line < call->call->nb_line && arg != NULL && def->def != NULL)
    {
      nb_octet += add_octet(arg);
      arg = arg->next;
    }
  nb_octet -= nb_octet * 2;
  return (nb_octet);
}

int		calc_with_call(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  while (arg->nb_line != call->call->nb_line && arg != NULL
	 && call->call != NULL)
    arg = arg->next;
  while (arg->nb_line <= def->nb_line && arg != NULL && def->def != NULL)
    {
      nb_octet += add_octet(arg);
      arg = arg->next;
    }
  return (nb_octet);
}

int		add_octet(t_cmd *arg)
{
  int		cpt;
  int		nb_octet;

  nb_octet = 0;
  cpt = 0;
  while (arg->arg[cpt] != 0)
    {
      nb_octet += arg->arg[pt];
      cpt++;
    }
  return (nb_octet);
}
