/*
** check_dot_name.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar  8 16:11:56 2016 
** Last update Tue Mar 22 14:27:03 2016 
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
	return (-1);
      if (i > PROG_NAME_LENGTH + 5)
	return (-1);
      i++;
    }
  return (0);
}
