/*
** check_dot_comment.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar  8 16:13:23 2016 
** Last update Mon Mar 21 14:46:23 2016 
*/

#include		"parser.h"
#include		"asm.h"

int			check_dot_comment(char *line)
{
  int			i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] > 128 || line[i] < 0)
	return (-1);
      if (i > COMMENT_LENGHT + 8)
	return (-1);
      i++;
    }
  return (0);
}
