/*
** stock_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
**
** Made by
** Login   <@epitech.net>
**
** Started on  Wed Mar 23 16:14:19 2016
** Last update Sun Mar 27 23:24:02 2016 loens_g
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"parser.h"
#include	"op.h"
#include	"pile_label.h"

char		if_octet_codage(char **tab, int cpt1, char output)
{
  if (tab[cpt1][0] == 'r')
    output = output | 1;
  else if (tab[cpt1][0] == '%')
    output = output | 2;
  else
    output = output | 3;
  output = output << 2;
  return (output);
}

char		setup_octet_codage(char *arg, char cpt)
{
  char		**tab;
  char		output;
  int		cpt1;
  int		cpt2;

  if (arg == NULL)
    return (0);
  if (cpt == OP_LIVE || cpt == OP_ZJMP || cpt == OP_FORK || cpt == OP_LFORK)
    return (0);
  cpt1 = -1;
  output = 0;
  if ((tab = my_str_to_wordtab(arg, &cpt2, ",")) == NULL)
    return (-1);
  while (++cpt1 < cpt2)
    {
      output = if_octet_codage(tab, cpt1, output);
    }
  free_str_wordtab(tab, cpt2);
  return (output);
}

t_cmd		*add_call(char *label, t_cmd *cmd)
{
  char		*label_new;

  if ((label_new = my_strdup(label)) == NULL)
    return (NULL);
  if ((cmd->head->call = stock_pile_for_call
       (cmd->head->call, label_new, cmd->nbr_line)) == NULL)
    return (NULL);
  return (cmd);
}

t_cmd		*type_arg(char *line, t_cmd *stock_arg, char **cmd, int nb)
{
  int		tofree;
  int		nb_argument;
  char		**arg;
  char		*totab;

  nb_argument = nb_argument_calc(line, stock_arg, cmd);
  totab = my_getword(line, 2);
  arg = my_str_to_wordtab(totab, &tofree, ",");
  free(totab);
  while (++nb < nb_argument)
    {
      if (arg_register(arg[nb]) == 0)
	{
	  stock_arg->type_arg[nb] = 1;
	  stock_arg->arg[nb] = my_getnbr_base(arg[nb]+1, "0123456789");
	}
      else if (arg_direct(arg[nb]) == 0)
	if ((case_direct(stock_arg, arg, nb)) == NULL)
	  return (NULL);
      if (arg_indirect(arg[nb]) == 0)
	if ((case_indirect(stock_arg, arg, nb)) == NULL)
	  return (NULL);
    }
  free_str_wordtab(arg, tofree);
  return (stock_arg);
}

t_cmd		*stock_cmd(char *line, t_cmd *stock_arg)
{
  char		**cmd;
  char		*tofree;

  if ((cmd = set_cmd_part1()) == NULL)
    return (NULL);
  stock_arg->opcode = (char)check_exist_cmd(line, cmd);
  tofree = my_getword(line, 2);
  if ((stock_arg->octet_codage =
       setup_octet_codage(tofree, stock_arg->opcode)) == -1)
    {
      free(tofree);
      free_tab_cmd(cmd);
      return (NULL);
    }
  free(tofree);
  if ((stock_arg = type_arg(line, stock_arg, cmd, -1)) == NULL)
    {
      free_tab_cmd(cmd);
      return (NULL);
    }
  free_tab_cmd(cmd);
  return (stock_arg);
}
