/*
** check_dot_comment.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar  8 16:13:23 2016 
** Last update Wed Mar 23 04:48:32 2016 
*/

#include		"parser.h"
#include		"op.h"
#include		"asm.h"

int			check_dot_comment(char *line)
{
  int			i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] < 0)
	return (error_message_parser1("no ascii caracter at caracter ", i));
      if (i > COMMENT_LENGTH + 8)
	return (error_message("size of comment is few long"));
      i++;
    }
  return (0);
}
