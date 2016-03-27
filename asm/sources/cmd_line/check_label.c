/*
** check_label.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
**
** Made by pillon_m
** Login   <@epitech.net>
**
** Started on  Tue Mar  8 16:20:12 2016 Maxime Pillon
** Last update Sun Mar 27 23:14:17 2016 loens_g
*/

#include	"op.h"
#include	"parser.h"
#include	"asm.h"

int		check_label(char *line)
{
  int		cpt;

  cpt = 0;
  while (line[cpt] != '\0' && line[cpt] != LABEL_CHAR)
    cpt++;
  if (line[cpt] == '\0')
    return (error_message("Label is incomplete "));
  if (line[cpt] == LABEL_CHAR)
    if (line[cpt + 1] == '\0')
      return (0);
  return (error_message("label has error "));
}
