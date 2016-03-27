/*
** stock_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/stock_arg
**
** Made by
** Login   <@epitech.net>
**
** Started on  Wed Mar 23 16:14:19 2016
** Last update Sat Mar 26 18:47:15 2016 
*/

#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"op.h"
#include	"pile_label.h"


#include	<unistd.h>
#include	<stdio.h>


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
  return (output);
}

t_cmd		*add_call(char *label, t_cmd *cmd)
{
  if ((cmd->head->call = stock_pile_for_call(cmd->head->call, label, cmd->nbr_line)) == NULL)
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

  val = check_exist_cmd(my_getword(line, 1), cmd);
  arg = my_str_to_wordtab(cmd[val + 1], &nb_argument, ",");
  arg = my_str_to_wordtab(my_getword(line, 2), &balec, ",");
  nb = -1;
  while (++nb < 3)
    {
      if (nb < nb_argument)
	{
	  if (arg_register(arg[nb]) == 0)
	    {
	      stock_arg->type_arg[nb] = 1;
	      /*printf("ce que j('nvoie a my_getnbr_base pour registre %s \n", arg[nb]+1);*/
	      stock_arg->arg[nb] = my_getnbr_base(arg[nb]+1, "0123456789");
	      /*printf("ce que recois a my_getnbr_base pour registre %d \n", stock_arg->arg[nb]);*/
	    }
	  else if (arg_direct(arg[nb]) == 0)
	    {
	      stock_arg->type_arg[nb] = T_DIR;
	      if (arg[nb][1] != ':')
		{
		  if (arg[nb][1] != '\0' && arg[nb][1] == '0' && arg[nb][2] != '\0' && arg[nb][2] == 'x')
		    {
		      /*printf("ce que j('nvoie a my_getnbr_base pour arg_direct %s \n", arg[nb]+3);*/
		      stock_arg->arg[nb] = my_getnbr_base(arg[nb]+3, "0123456789ABCDEF");
		      /*printf("ce que je recois a my_getnbr_base pour arg_direct %d \n", stock_arg->arg[nb]);*/
		    }
		  else
		    {
		      /*printf("ce que j('nvoie a my_getnbr_base pour arg_direct %s \n", arg[nb]+1);*/
		      stock_arg->arg[nb] = my_getnbr_base(arg[nb]+1, "0123456789");
		      /*printf("ce que je recois a my_getnbr_base pour arg_direct %d \n", stock_arg->arg[nb]);*/
		    }
		}
	      else
		{
		  if ((stock_arg = add_call(arg[nb]+2, stock_arg)) == NULL)
		    return (NULL);
		  stock_arg->type_arg[nb] += 10;
		}
	    }
	  else if (arg_indirect(arg[nb]) == 0)
	    {
	      stock_arg->type_arg[nb] = T_IND;
	      if (arg[nb][0] != ':')
		{
		  if (arg[nb][0] != '\0' && arg[nb][0] == '0' && arg[nb][1] != '\0' && arg[nb][1] == 'x')
		    {
		      /*printf("ce que j('nvoie a my_getnbr_base pour arg_indirect %s \n", arg[nb]+2);*/
		      stock_arg->arg[nb] = my_getnbr_base(arg[nb]+2, "0123456789");
		      /*printf("ce que je recois a my_getnbr_base pour arg_indirect %d \n", stock_arg->arg[nb]);*/
		    }
		  else
		    {
		      /* printf("ce que j('nvoie a my_getnbr_base pour arg_indirect %s \n", arg[nb]);*/
		      stock_arg->arg[nb] = my_getnbr_base(arg[nb], "0123456789");
		      /*printf("ce que je recois a my_getnbr_base pour arg_indirect %d \n", stock_arg->arg[nb]);*/
		    }
		}
	      else
		{
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
  /*printf("%d \n", stock_arg->opcode);*/
  if ((stock_arg->octet_codage = setup_octet_codage(my_getword(line, 2), stock_arg->opcode)) == -1)
    return (NULL);
  if ((stock_arg = type_arg(line, stock_arg, cmd)) == NULL)
    return (NULL);
  return (stock_arg);
}
