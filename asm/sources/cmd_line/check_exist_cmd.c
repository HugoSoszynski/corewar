/*
** check_exist_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar  7 19:23:44 2016 
** Last update Mon Mar 21 15:15:17 2016 
*/

int		check_exist_cmd(char *line,
				char **cmd)
{
  int		cpt;

  cpt = 0;
  while (cpt < 32)
    {
      if (my_strcmp(line, cmd[cpt]) == 0)
	return (cpt);
      cpt += 2;
    }
  return (-1);
}
