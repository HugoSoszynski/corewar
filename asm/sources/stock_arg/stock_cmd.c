/*
** stock_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Wed Mar 23 16:14:19 2016 
** Last update Wed Mar 23 21:44:47 2016 
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

t_cmd		*arg_and_type_arg(char *line, t_cmd *stock_arg)
{
char		**cmd  
}

t_cmd		*stock_cmd(char *line, t_cmd *stock_arg)
{
  char		**cmd;

  if ((cmd = set_tab_part1()) == NULL)
    return (NULL);
  (int)(stock_arg->opcode) = check_exist_cmd(line, cmd); // opcode
  if ((stock_arg->octet_codage = setup_octet_codage(my_getword(line, 2))) == -1)
    return (NULL);
  if ((stock = arg_and_type_arg(line, stock_arg)) == NULL)
    return (NULL);

}
