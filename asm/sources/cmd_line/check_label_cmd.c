/*
** check_label_cmd.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by
** Login   <@epitech.net>
**
** Started on  Tue Mar  8 16:21:23 2016
** Last update Tue Mar 22 10:23:50 2016 
*/

#include		"parser.h"
#include		"asm.h"

int			check_label_cmd(char *line)
{
  int			cpt;

  cpt = 0;
  while (line[cpt] != '\0' && line[cpt] != ' ')
    cpt++;
  if (line[cpt + 1] == '\0')
    return (-1);
  if (check_cmd(line + cpt + 1) == -1)
    return (-1);
  return (0);
}
