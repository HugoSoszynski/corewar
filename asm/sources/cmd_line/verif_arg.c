/*
** verif_arg.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by
** Login   <@epitech.net>
**
** Started on  Mon Mar  7 16:16:00 2016
** Last update Mon Mar  7 18:17:53 2016 Grégoire Loens
*/

int		verif_nbr_arg(char *line, char **cmd)
{
  int		pos;
  int		nbr_arg;
  int		cpt;

  cpt = 0;
  nbr_arg = 0;
  pos = check_exist_cmd(line, cmd);
  while (line[cpt] != 0)
    {
      if (line[cpt] == ',')
	nbr_arg++;
      cpt++;
    }
  if (nbr_arg + 1 != my_getnbr(cmd[pos + 1][0]))
    return (-1);
  else
    return (nbr_arg);
}

int		use_of_arg(char *line)
{
  int		cpt;

  cpt = 0;
}
