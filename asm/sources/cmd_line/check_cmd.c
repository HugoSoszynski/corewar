/*
** verif_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by
** Login   <@epitech.net>
**
** Started on  Mon Mar  7 16:10:58 2016
** Last update Wed Mar 23 17:50:15 2016 
*/

#include	<stddef.h>
#include	"parser.h"
#include	"asm.h"

#include	<unistd.h>
#include	<stdio.h>

int		check_validity(char *line, char **cmd)
{
  int		arg_cmd_line;
  int		cpt;
  int		nb_arg_need;
  int		nb_arg_have;
  char		*arg;
  char		**arg_of_cmd_tab;
  char		**arg_of_cmd;

  cpt = 0;
  arg_cmd_line = check_exist_cmd(my_getword(line, 1), cmd) + 1;
  arg = my_getword(line, 2);
  arg_of_cmd_tab = my_str_to_wordtab(cmd[arg_cmd_line], &nb_arg_need, ",");
  arg_of_cmd = my_str_to_wordtab(arg, &nb_arg_have, ",");
  if (nb_arg_need != nb_arg_have)
    return (error_message("wrong number of argument "));
  while (cpt < nb_arg_have)
    {
      if ((check_one_arg(arg_of_cmd[cpt], arg_of_cmd_tab[cpt])) == -1)
	return (error_message_parser1("You have an error for your argument number ", cpt+1));
      cpt++;
    }
  return (0);
}

/* quand asm retestable svp changer la ligne check_exist_cmd elle permet une multiple definition de fonction c'est la merde oublie pas connard de pillon ou de loens de merde */

int		check_cmd(char *line)
{
  char		**cmd;
  int		word_nbr;
  char		*word;

  word_nbr = 2;
  cmd = set_cmd_part1();
  word = my_getword(line, 1);
 if (check_exist_cmd(word, cmd) == -1)
    return (-1);
  while ((word = my_getword(line, word_nbr)) != NULL)
    {
      if (check_exist_cmd(word, cmd) == 0)
	return (error_message("too much function declaration on at line"));
      word_nbr++;
    }
  if (check_validity(line, cmd) == -1)
    return (-1);
  return (0);
}
