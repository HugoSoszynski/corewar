/*
** verif_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by
** Login   <@epitech.net>
**
** Started on  Mon Mar  7 16:10:58 2016
** Last update Sun Mar 27 18:22:10 2016 
*/

#include	<stddef.h>
#include	"parser.h"
#include	"asm.h"
#include	<stdlib.h>

void		free_check_validity(char **tab1, char **tab2, int limit1, int limit2)
{
  int		cpt;

  cpt = -1;
  while (++cpt < limit1)
    free(tab1[cpt]);
  free(tab1);
  cpt = -1;
  while (++cpt < limit2)
    free(tab2[cpt]);
  free(tab2);
}

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
  arg = my_getword(line, 1);
  arg_cmd_line = check_exist_cmd(arg, cmd) + 1;
  free(arg);
  arg = NULL;
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
  free(arg);
  free_check_validity(arg_of_cmd_tab, arg_of_cmd, nb_arg_need, nb_arg_have);
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
    return (error_message("no function declared at line "));
  free(word);
  word = NULL;
  while ((word = my_getword(line, word_nbr)) != NULL)
    {
      if (check_exist_cmd(word, cmd) != -1)
	{
	  free(word);
	  word = NULL;
	  return (error_message("too much function declaration at line"));
	}
      free(word);
      word = NULL;
      word_nbr++;
    }
  if (check_validity(line, cmd) == -1)
    return (-1);
  free_tab_cmd(cmd);
  return (0);
}
