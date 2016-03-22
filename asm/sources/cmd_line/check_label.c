/*
** check_label.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar  8 16:20:12 2016 
** Last update Tue Mar 22 14:33:59 2016 
*/

#include	"parser.h"
#include	"asm.h"

int		check_label(char *line)
{
  int		cpt;

  cpt = 0;
  while (line[cpt] != '\0' && line[cpt] != ':')
    cpt++;
  if (line[cpt] == '\0')
    return (error_message("Label is incomplete "));
  if (line[cpt] == ':')
    if (line[cpt + 1] == '\0')
      return (0);
  return (error_message("label has error"));
}
