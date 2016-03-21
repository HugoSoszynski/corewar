/*
** parser.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 10:53:24 2016 Grégoire Loens
** Last update Mon Mar 21 12:22:52 2016 
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

int		gst_code(char *line)
{
  int		cpt;

  cpt = 5;
  if (my_strcmp(line, ".code") == -1)
    return (-1);
  while (line[cpt] != 0)
    {
      if (line[cpt] != ' ')
	return (-1);
      if (line[cpt + 1] >= '0' && line[cpt + 1] <= '9' && line[cpt + 1] >= 'a'
	  && line[cpt + 1] <= 'z' && line[cpt + 1] >= 'A'
	  && line[cpt + 1] <= 'Z')
	return (-1);
      if (line[cpt + 2] >= '0' && line[cpt + 2] <= '9' && line[cpt + 2] >= 'a'
	  && line[cpt + 2] >= 'z' && line[cpt + 2] <= 'A' 
	  && line[cpt + 2] <= 'Z')
	return (-1);
      cpt += 3;
    }
}

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

int		gst_extend(char *line)
{
  int		cpt;

  cpt = 8;
  if (my_strcmp(line, ".extend") == -1)
    return (-1);
  if (line[cpt] != 0)
    return (-1);
  return (0);
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
