/*
** check_label.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar  8 16:20:12 2016 
** Last update Mon Mar 21 18:33:43 2016 
*/

int		check_label(char *line)
{
  int		cpt;

  cpt = 0;
  while (line[cpt] != '\0' && line[cpt] != ':')
    cpt++;
  if (line[cpt] == '\0')
    return (error_message("Label is incomplete "));
  if (line[cpt] == ':')
    if (line[cpt] == '\0')
      return (error_message());
}
