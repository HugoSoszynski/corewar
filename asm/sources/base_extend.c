/*
** base_extend.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sun Mar 27 23:05:17 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 23:05:25 2016 Hugo SOSZYNSKI
*/

#include        "op.h"
#include        "asm.h"
#include        "parser.h"

int             my_strcmp(char *str1, char *str2)
{
  int           cpt;

  cpt = 0;
  while (str1[cpt] && str2[cpt] && str1[cpt] == str2[cpt])
    ++cpt;
  if (!str2[cpt] && (str1[cpt] == ' ' || str1[cpt] == '\0'))
    return (0);
  return (-1);
}
