/*
** stock_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
**
** Made by
** Login   <@epitech.net>
**
** Started on  Wed Mar 23 16:14:19 2016
** Last update Fri Mar 25 06:07:09 2016 
*/

#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"op.h"
#include	"pile_label.h"


#include	<unistd.h>
#include	<stdio.h>


char		if_octet_codage(char **tab, int cpt1, int n, char output)
{
  if (tab[cpt1][0] == 'r')
    output |= (0 << n);
  if (tab[cpt1][0] == 'r')
    output |= (1 << (n + 1));
  else if (tab[cpt1][0] == '%')
    output |= (1 << n);
  if (tab[cpt1][0] == '%')
    output |= (0 << (n + 1));
  else
    {
      output |= (1 << n);
      output |= (1 << (n + 1));
    }
  return (output);
}

char		setup_octet_codage(char *arg, char cpt)
{
  char		**tab;
  char		output;
  int		n;
  int		cpt1;
  int		cpt2;
  
  if (arg == NULL)
    return (0);
  if (cpt == OP_LIVE || cpt == OP_ZJMP || cpt == OP_FORK || cpt == OP_LFORK)
    return (0);
  n = 0;
  cpt1 = -1;
  output = 0;
  if ((tab = my_str_to_wordtab(arg, &cpt2, ",")) == NULL)
    return (-1);
  while (++cpt1 < cpt2)
    {
      output = if_octet_codage(tab, cpt1, n, output);
      n += 2;
    }
  return (output);
}

t_cmd		*add_call(char *label, t_cmd *cmd)
{
  if ((cmd->call = stock_pile_for_call(cmd->call, label, cmd->nbr_line)) == NULL)
    return (NULL);
  return (cmd);
}

t_cmd		*type_arg(char *line, t_cmd *stock_arg, char **cmd)
{
  int		nb;
  int		val;
  int		balec;
  int		nb_argument;
  char		**arg;

  /*printf ("%s ttotototototoot \n", my_getword(line, 1));*/
  val = check_exist_cmd(my_getword(line, 1), cmd);
  arg = my_str_to_wordtab(cmd[val + 1], &nb_argument, ",");
  arg = my_str_to_wordtab(my_getword(line, 2), &balec, ",");
  nb = -1;
  while (++nb < 3)
  {
    printf("%d ----- %d \n", nb, nb_argument);
    if (nb < nb_argument)
      {
	printf("%s \n", arg[nb]);
	if (arg_register(arg[nb]) == 0)
	  {
	    printf ("passe par register \n");
	    stock_arg->type_arg[nb] = 1;
	    stock_arg->arg[nb] = my_getnbr_base(arg[nb]+1, "0123456789");
	  }
	else if (arg_direct(arg[nb]) == 0)
	  {
	    stock_arg->type_arg[nb] = 2;
	    if (arg[nb][1] != ':')
	      {
		printf ("direct mais pas label");
	      stock_arg->arg[nb] = my_getnbr_base(arg[nb]+1, "0123456789");
	      }
	      else
	      {
		write (1, "add_arg", 7);
		if ((stock_arg = add_call(arg[nb]+2, stock_arg)) == NULL)
		  return (NULL);
		stock_arg->type_arg[nb] += 10;
	      }
	  }
	else if (arg_indirect(arg[nb]) == 0)
	  {
	    stock_arg->type_arg[nb] = 4;
	    if (arg[nb][0] != ':')
	      {
		printf ("indirect mais pas label");
	      stock_arg->arg[nb] = my_getnbr_base(arg[nb], "0123456789");
	      }
	      else
	      {
		write (1, "add_arg", 7);
		if ((stock_arg = add_call(arg[nb]+2, stock_arg)) == NULL)
		  return (NULL);
		stock_arg->type_arg[nb] += 10;
	      }
	  }
      }
    else
      stock_arg->type_arg[nb] = 0;
  }
  return (stock_arg);
}

t_cmd		*stock_cmd(char *line, t_cmd *stock_arg)
{
  char		**cmd;

  if ((cmd = set_cmd_part1()) == NULL)
    return (NULL);
  stock_arg->opcode = (char)check_exist_cmd(line, cmd); // opcode
  if ((stock_arg->octet_codage = setup_octet_codage(my_getword(line, 2), stock_arg->opcode)) == -1)
    return (NULL);
  if ((stock_arg = type_arg(line, stock_arg, cmd)) == NULL)
    return (NULL);
  return (stock_arg);
}
