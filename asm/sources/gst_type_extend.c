/*
** gst_type_extend.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar 22 11:57:24 2016 
** Last update Tue Mar 22 18:27:55 2016 
*/

#include	"parser.h"
#include	"asm.h"

int		gst_code(char *line)
{
  if (line[0] != '.')
    return (-1);
  else
    if (my_strcmp(line, ".code") != -1)
      return (0);
    else
      return (-1);
}
