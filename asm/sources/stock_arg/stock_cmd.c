/*
** stock_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
**
** Made by
** Login   <@epitech.net>
**
** Started on  Wed Mar 23 16:14:19 2016
** Last update Thu Mar 24 13:55:32 2016 Grégoire Loens
*/

#include	"asm.h"
#include	"parser.h"

char		if_octet_codage(char **tab, int cpt1, int n, char output)
{
  if (tab[cpt1][0] == 'r')
    output |= (0 << n);
  if (tab[cpt1][0] == 'r')
    output |= (1 << n + 1);
  else if (tab[cpt1][0] == '%')
    output |= (1 << n);
  if (tab[cpt1][0] == '%')
    output |= (0 << n + 1);
  else
    {
      output |= (1 << n);
      output |= (1 << n + 1);
    }
  return (output);
}

char		setup_octet_codage(char *arg)
{
  char		**tab;
  char		output;
  int		n;
  int		cpt1;
  int		cpt;

  n = 0;
  cpt1 = -1;
  output = 0;
  if ((tab = my_str_to_wordtab(arg, &cpt, ",")) == NULL)
    return (-1);
  while (++cpt1 < cpt)
    {
      output = if_octet_codage(tab, cpt1, n, output);
      n += 2;
    }
}

t_cmd		*my_arg(char **arg, int nb)
{

}

t_cmd		*type_arg(char *line, t_cmd *stock_arg, char **cmd)
{
  char		**cmd;
  int		nb;
  int		nb_argument;
  char		**arg;

  arg = my_str_to_wordtab((check_exist_cmd(line, cmd) + 1), &nb_argument, ',');
  nb = -1;
  while (arg[++nb] != 0);
    {
      if (arg_direct(arg[nb]) == 1)
	stock_arg->type_arg[nb] = 1;
      if (arg_direct(arg[nb]) == 1)
	stock_arg->arg[nb] = ;
      else if (arg_direct(arg[nb]) == 1)
	stock_arg->type_arg[nb] = 2;
      if (arg_direct(arg[nb]) == 1)
	stock_arg->arg[nb] = ;
      else if (arg_indirect(arg[nb]) == 1)
	stock_arg->type_arg[nb] = 4;
      if (arg_indirect(arg[nb]) == 1)
	stock_arg->arg[nb] = ;
      else
	stock->type_arg[nb] = 0;
    }
  return (stock_arg);
}

t_cmd		*stock_cmd(char *line, t_cmd *stock_arg)
{
  char		**cmd;

  if ((cmd = set_tab_part1()) == NULL)
    return (NULL);
  (int)(stock_arg->opcode) = check_exist_cmd(line, cmd); // opcode
  if ((stock_arg->octet_codage = setup_octet_codage(my_getword(line, 2))) == -1)
    return (NULL);
  if ((stock = arg_and_type_arg(line, stock_arg cmd)) == NULL)
    return (NULL);

}
