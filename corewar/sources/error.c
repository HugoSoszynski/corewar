/*
** error.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 13:40:34 2016 Grégoire Loens
** Last update Mon Mar 21 21:22:48 2016 corsin_a
*/

#include	<unistd.h>
#include	"corewar.h"

int		my_strlen(char *str)
{
  int		cpt;

  cpt = 0;
  while(str[cpt] != '\0')
    cpt++;
  return (cpt);
}

int		error_nbr(char *start, int nb, char *end)
{
  write(2, start, my_strlen(start));
  my_putnbr(nb);
  write(2, end, my_strlen(end));
  return (ERROR);
}

int		error_message(char *message)
{
  write(2, message, my_strlen(message));
  write(2, "\n", 1);
  return (ERROR);
}

int		error_file(char *start, char *name, char *end)
{
  write(2, start, my_strlen(start));
  write(2, name, my_strlen(name));
  write(2, end, my_strlen(end));
  write(2, "\n", 1);
  return (ERROR);
}
