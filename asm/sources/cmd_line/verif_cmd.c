/*
** verif_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by
** Login   <@epitech.net>
**
** Started on  Mon Mar  7 16:10:58 2016
** Last update Mon Mar  7 20:23:55 2016 
*/

char		**set_cmd_part1()
{
  char		**cmd;

  cmd[0] = "live";
  cmd[1] = "1d";
  cmd[2] = "ld";
  cmd[3] = "2d/i,r";
  cmd[4] = "st";
  cmd[5] = "3r,d/r";
  cmd[6] = "add";
  cmd[7] = "3r,r,r";
  cmd[8] = "sub";
  cmd[9] = "3r,r,r";
  cmd[10] = "and";
  cmd[11] = "3r/d/i,r/d/i,r";
  cmd[12] = "or";
  cmd[13] = "3r/d/i,r/d/i,r";
  cmd[14] = "xor";
  cmd[15] = "3r/d/i,r/d/i,r";
  cmd[16] = "zjmp";
  cmd[17] = "1d";
  cmd[18] = "ldi";
  cmd[19] = "2r/d/i,r/d/i";
  cmd[20] = "sti";
  cmd[21] = "3r,r/d/i,r/d";
  return (set_cmd_part2(cmd));
}

char		**set_cmd_part2(char **cmd)
{
  cmd[22] = "fork";
  cmd[23] = "1d";
  cmd[24] = "lfork";
  cmd[25] = "1d";
  cmd[26] = "lld";
  cmd[27] = "2d/i,r";
  cmd[28] = "lldi";
  cmd[29] = "2r/d/i,r/d,r";
  cmp[30] = "aff";
  cmp[31] = "1r";
  cmp[32] = ".name";
  cmp[33] = ".comment"
  return (cmd);
}

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
  return (7);
}

int		verif_nbr_cmd(char *line)
{
  char		**cmd;
  int		cpt;
  int		word_nbr;
  char		*word;

  word_nbr = 2;
  cpt = -1;
  cmd = set_cmd_part1();
  word = my_getword(line, 1);
  while (word[++cpt] != '\0');
  if (word[cpt - 1] == ':')
    return (verif_nbr_cmd_label(line, cmd));
  if (check_exist_cmd(word, cmd) == -1) /*a coder (verif existance de cmd) */
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
