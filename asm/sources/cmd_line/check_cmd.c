/*
** verif_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by
** Login   <@epitech.net>
**
** Started on  Mon Mar  7 16:10:58 2016
** Last update Tue Mar  8 17:22:21 2016 
*/

int		check_validity(char *line, char **cmd)
{
  int		arg_cmd;
  int		cpt;
  char		*arg;

  arg_cmd = check_exist_cmd(my_getword(line, 1), cmd) + 1;
  arg = my_getword(
}

int		check_cmd(char *line)
{
  char		**cmd;
  int		cpt;
  int		word_nbr;
  char		*word;

  word_nbr = 2;
  cpt = -1;
  cmd = set_cmd_part1();
  word = my_getword(line, 1);
  if (check_exist_cmd(word, cmd) == -1)
    return (-1);
  word = my_getword(line, word_nbr);
  while ((word = my_getword(line, word_nbr)) != NULL)
    /* while qui verifie qu'aucun notre mots est une commande */
    {
      if (check_exist_cmd(word, cmd) == 0)
	return (-1);
      word_nbr++;
    }
  if (check_validity_cmd(line, cmd) == -1)
    return (-1);
  return (0);
}
