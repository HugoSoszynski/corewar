/*
** stock_cmd_extend.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
** 
** Made by Maxime Pillon
** Login   <pillon_m@epitech.net>
** 
** Started on  Sun Mar 27 22:14:05 2016 
** Last update Sun Mar 27 22:44:39 2016 
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"parser.h"
#include	"op.h"
#include	"pile_label.h"

int		nb_argument_calc(char *line, t_cmd *stock_arg, char **cmd)
{
  int		val;
  int		nb_argument;
  char		*totab;
  char		**arg;

  (void)stock_arg;
  totab = my_getword(line, 1);
  val = check_exist_cmd(totab, cmd);
  free(totab);
  arg = my_str_to_wordtab(cmd[val + 1], &nb_argument, ",");
  free_str_wordtab(arg, nb_argument);
  return (nb_argument);
}

char		*case_direct(t_cmd *stock_arg, char **arg, int nb)
{
  stock_arg->type_arg[nb] = T_DIR;
  if (arg[nb][1] != ':')
    {
      if (arg[nb][1] != '\0' && arg[nb][1] == '0' && arg[nb][2] != '\0' && arg[nb][2] == 'x'\
	  )
	stock_arg->arg[nb] = my_getnbr_base(arg[nb]+3, "0123456789ABCDEF");
      else
	stock_arg->arg[nb] = my_getnbr_base(arg[nb]+1, "0123456789");
    }
  else
    {
      if ((stock_arg = add_call(arg[nb]+2, stock_arg)) == NULL)
	return (NULL);
      stock_arg->type_arg[nb] += 10;
    }
  return (arg[nb]);
}

char		*case_indirect(t_cmd *stock_arg, char **arg, int nb)
{
  stock_arg->type_arg[nb] = T_IND;
  if (arg[nb][0] != ':')
    {
      if (arg[nb][0] != '\0' && arg[nb][0] == '0' && arg[nb][1] != '\0' && arg[nb][1] == 'x'\
	  )
	stock_arg->arg[nb] = my_getnbr_base(arg[nb]+2, "0123456789");
      else
	stock_arg->arg[nb] = my_getnbr_base(arg[nb], "0123456789");
    }
  else
    {
      if ((stock_arg = add_call(arg[nb]+2, stock_arg)) == NULL)
	return (NULL);
      stock_arg->type_arg[nb] += 10;
    }
  return (arg[nb]);
}
