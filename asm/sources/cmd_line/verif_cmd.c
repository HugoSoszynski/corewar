/*
** verif_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar  7 16:10:58 2016 
** Last update Mon Mar  7 17:04:51 2016 
*/

int		verif_nbr_cmd_label(char *line)
{
  int		word_nbr;
  char		*word;

  word_nbr = 3;
  word = my_getword(line, 2);
  if (check_exist_cmd(word) == -1)
    return (-1);
  while ((word = my_getword(line, word_nbr)) != NULL)
    {
      if (check_exist_cmd(word) == 0)
	return (-1);
      word_nbr++;
    }
  return (0);
}

int		verif_nbr_cmd(char *line)
{
  int		cpt;
  int		word_nbr;
  char		*word;

  word_nbr = 2;
  cpt = -1;
  word = my_getword(line, 1);
  while (word[++cpt] != '\0');
  if (word[cpt - 1] == ':')
    if (verif_nbr_cmd_label(line) == -1)
      return (-1);
  if (check_exist_cmd(word) == -1) /*a coder (verif existance de cmd) */
    return (-1);
  word = my_getword(line, word_nbr);
  while ((word = my_getword(line, word_nbr)) != NULL) /* while qui verifie qu'aucun notre mots est une commande */
    {
      if (check_exist_cmd(word) == 0)
	return (-1);
      word_nbr++;
    }
  return (0);
}

int		command_with_arg(char *line)
{
  int		cpt;

  cpt = 0;
}
