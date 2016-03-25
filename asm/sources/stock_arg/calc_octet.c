/*
** calc_octet.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/stock_arg/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Thu Mar 24 23:20:29 2016 Grégoire Loens
** Last update Fri Mar 25 17:39:41 2016 
*/

#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"pile_label.h"

int		calc_with_def(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  int		nb_octet;

  nb_octet = 0;
  while (arg->nbr_line != def->def->nb_line && arg != NULL && def->def != NULL)
    arg = arg->next;
  while (arg->nbr_line < call->call->nb_line && arg != NULL && def->def != NULL)
    {
      nb_octet += add_octet(arg);
      arg = arg->next;
    }
  nb_octet -= nb_octet * 2;
  return (nb_octet);
}

int		calc_with_call(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  int		nb_octet;

  nb_octet = 0;
  while (arg->nbr_line != call->call->nb_line && arg != NULL
	 && call->call != NULL)
    arg = arg->next;
  while (arg->nbr_line <= def->nbr_line && arg != NULL && def->def != NULL)
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
  if (arg->type == TYPE_LINE_CODE)
    nb_octet += arg->dot_code_octet;
  else
    while (arg->arg[cpt] != 0)
      {
	nb_octet += arg->arg[cpt];
	cpt++;
      }
  return (nb_octet);
}
