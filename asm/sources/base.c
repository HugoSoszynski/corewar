/*
** base.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar 22 18:30:56 2016 
** Last update Tue Mar 22 18:34:05 2016 
*/

#include	"asm.h"
#include	"parser.h"

int		my_isalpha(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < 'a' || str[i] > 'z') || (str[i] < 'A' || str[i] > 'Z'))
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
