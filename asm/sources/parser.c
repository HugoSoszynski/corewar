/*
** parser.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 10:53:24 2016 Grégoire Loens
** Last update Mon Mar  7 14:10:48 2016 Grégoire Loens
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

int		verif_beginning_file(int fd)
{
  char		*line;
  int		nbr_line;

  counter = -1;
  while (++nbr_line < 2)
    {
      line = get_next_line(fd);
      if (line == NULL)
	return (error_message("Error: empty file\n"));
      if (i == 0)
	{
	  if (gst_name(line) == -1)
	    return (error_message("Syntax error line 1"));
        }
      if (i == 1)
	{
	  if (gst_comment(line) == -1)
	    return (error_message("Syntax error line 2"));
	}
    }
}
