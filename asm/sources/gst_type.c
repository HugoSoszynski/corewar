/*
** parser.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 10:53:24 2016 Grégoire Loens
** Last update Wed Mar 23 11:40:24 2016 
*/

#include 	<stddef.h>
#include	"parser.h"
#include	"asm.h"
#include	"op.h"


#include	<unistd.h>
#include	<stdio.h>

int		gst_comment(char *line)
{
  int		cpt;
  int		cpt1;

  cpt = 7;
  cpt1 = 0;
  if (my_strcmp(line, ".comment") == -1)
    return (-1);
  while (line[cpt] != '\0')
    {
      if (line[cpt] == '"')
	cpt1++;
      cpt++;
    }
  if (cpt1 != 2)
    return (-1);
  return (0);
}

int		gst_name(char *line)
{
  int		cpt;
  int		cpt1;
  
  cpt = 5;
  cpt1 = 0;
  if (my_strcmp(line, ".name") == -1)
    {
      return (-1);
    }
  while (line[cpt] != '\0')
    {
      if (line[cpt] == '"')
	cpt1++;
      cpt++;
    }
  if (cpt1 != 2)
    return (-1);
  return (0);
}

int		gst_cmd(char *line, char **cmd)
{
  int		cpt;
  int		cpt1;

  cpt = 0;
  while (cpt < 30)
    {
      cpt1 = 0;
      /*printf("%s %d \n", cmd[cpt], cpt);*/
      if (my_strcmp(line, cmd[cpt]) != -1)
	{
	  while (line[cpt1] != '\0' && line[cpt1] != ' ')
	    {
	      if (line[cpt1] == LABEL_CHAR)
		return (-1);
	      cpt1++;
	    }
	  return (0);
       	}
      cpt += 2;
    }
  return (-1);
}

int		gst_extend(char *line)
{
  if (my_strcmp(line, ".extend") == -1)
    return (-1);
  else
    return (0);
}

int		gst_label(char	*line)
{
  int		cpt;

  cpt = 0;
  while (line[cpt] != '\0' && line[cpt] != LABEL_CHAR)
    {
      if (my_islabelchar(line[cpt]) == -1)
	return (-1);
      cpt++;
    }
  if (line[cpt] == '\0')
    return (-1);
  cpt += 1;
  if ((line[cpt] == '\0') || (line[cpt] == ' ' && line[cpt + 1] == '\0'))
    return (1);
  else
    return (2);
  return (-1);
}
