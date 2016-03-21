/*
** parser.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 10:53:24 2016 Grégoire Loens
** Last update Tue Mar  8 15:49:58 2016 Grégoire Loens
*/

#include 	"stddef.h"
#include	"parser.h"

int		gst_comment(char *line)
{
  int		cpt;

  cpt = 7;
  if (my_strcmp(line, ".comment") == -1)
    return (-1);
  if (line[my_strlen(line) - 1] != "34")
    return (-1);
  while (line[cpt] == ' ' && line[cpt] == '\t' && line[cpt] != '\0')
    cpt++;
  if (line[cpt] != '"')
    return (-1);
}

int		gst_name(char *line)
{
  int		cpt;

  cpt = 5;
  if (my_strcmp(line, ".name") == -1)
    return (-1);
  if (line[my_strlen(line) - 1] != "34")
    return (-1);
  while (line[cpt] == ' ' && line[cpt] == '\t' && line[cpt] != '\0')
    cpt++;
  if (line[cpt] != '"')
    return (-1);
}

int		gst_cmd(char *line)
{
  int		cpt;

  cpt = 0;
  while (cpt != 30)
    {
      if (my_strcmp(line, cmd[cpt]) != -1)
	return (0);
      cpt += 2;
    }
  return (-1);
}
