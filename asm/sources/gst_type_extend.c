/*
** gst_type_extend.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sun Mar 27 23:10:39 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 23:10:54 2016 Hugo SOSZYNSKI
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
