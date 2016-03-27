/*
** calc_octet.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/stock_arg/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Thu Mar 24 23:20:29 2016 Grégoire Loens
** Last update Sun Mar 27 23:33:21 2016 Hugo SOSZYNSKI
*/

#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"pile_label.h"

void		set_octet(t_cmd *arg, t_cmd *call, int nb_octet)
{
  int		cpt;

  cpt = 0;
  arg = arg->head;
  while (arg != NULL && arg->nbr_line < call->call->nb_line)
    arg = arg->next;
  while (arg != NULL && arg->type_arg[cpt] != 12 && arg->type_arg[cpt] != 14
	 && arg->arg[cpt] != 0)
    cpt++;
  arg->arg[cpt] = nb_octet;
}

int		add_octet_def(t_cmd *arg, t_pile *start)
{
  int		nb_octet;
  int		cpt;

  cpt = 0;
  nb_octet = 0;
  while (arg != NULL && arg->nbr_line < start->nb_line)
    {
            nb_octet += 1;
      if (arg->octet_codage != 0)
	nb_octet += 1;
      if (arg->opcode == OP_LLDI
	  || arg->opcode == OP_LDI || arg->opcode == OP_STI)
	nb_octet += 5;
      else if (arg->opcode == OP_FORK
	       || arg->opcode == OP_LFORK || arg->opcode == OP_ZJMP)
	nb_octet += 2;
      else if (arg->opcode == OP_LIVE)
	nb_octet += 4;
      else
	while (cpt < 3)
	  {
	    nb_octet += arg->type_arg[cpt];
	    cpt++;
	  }
      cpt = 0;
      arg = arg->next;
    }
  return (nb_octet);
}

int		calc_call(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  int		nb_octet;

  (void)call;
  nb_octet = 0;
  nb_octet = add_octet_def(arg, def->def);
  return (nb_octet);
}

int		calc_def(t_cmd *call, t_cmd *def, t_cmd *arg)
{
  int		nb_octet;

  arg = arg->head;
  while (arg != NULL && arg->nbr_line < def->def->nb_line)
    arg = arg->next;
  nb_octet = add_octet_def(arg, call->call);
  nb_octet *= -1;
  return (nb_octet);
}
