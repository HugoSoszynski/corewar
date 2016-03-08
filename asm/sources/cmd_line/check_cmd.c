/*
** verif_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by
** Login   <@epitech.net>
**
** Started on  Mon Mar  7 16:10:58 2016
** Last update Tue Mar  8 16:10:19 2016 
*/

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
  while ((word = my_getword(line, word_nbr)) != NULL) /* while qui verifie qu'aucun notre mots est une commande */
    {
      if (check_exist_cmd(word) == 0)
	return (-1);
      word_nbr++;
    }
  // add fonction qui verifie si les argument associer a la commande sont valide
  return (0);
}
