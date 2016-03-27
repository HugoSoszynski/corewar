/*
** check_dot_name.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by pillon_m
** Login   <@epitech.net>
**
** Started on  Tue Mar  8 16:11:56 2016 Maxime Pillon
** Last update Sun Mar 27 23:12:42 2016 loens_g
*/

#include	"parser.h"
#include	"asm.h"
#include	"op.h"

int		check_dot_name(char *line)
{
  int		i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] < 0)
	return (error_message_parser1("no ascii caracter at caracter ", i));
      if (i > PROG_NAME_LENGTH + 5)
	return (error_message(".name has a few long size "));
      i++;
    }
  return (0);
}
