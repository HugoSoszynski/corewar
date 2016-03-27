/*
** base_extend.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by Maxime Pillon
** Login   <pillon_m@epitech.net>
** 
** Started on  Sun Mar 27 20:49:08 2016 
** Last update Sun Mar 27 20:50:48 2016 
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

