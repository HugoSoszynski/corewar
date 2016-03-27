/*
** base.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar 22 18:30:56 2016 
** Last update Sun Mar 27 20:49:46 2016 
*/

#include	"op.h"
#include	"asm.h"
#include	"parser.h"

int             my_strlen(const char *str)
{
  int           i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int		my_islabelchar(char c)
{
  int		cpt;

  cpt = -1;
  while (LABEL_CHARS[++cpt] != '\0' && LABEL_CHARS[cpt] != c);
  if (LABEL_CHARS[cpt] == '\0')
    return (-1);
  return (0);
}

int		my_islabel(char *str)
{
  int		cpt;
  int		cpt1;
  
  cpt = 0;
  while (str[cpt] != '\0')
    {
      cpt1 = -1;
      while (LABEL_CHARS[++cpt1] != '\0' && LABEL_CHARS[cpt1] != str[cpt]);
      if (LABEL_CHARS[cpt1] == '\0')
	return (-1);
      cpt++;
    }
  return (0);
}

int		my_isalpha(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
	return (-1);
      i++;
    }
  return (0);
}

int		my_isnum(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (-1);
      i++;
    }
  return (0);
}
