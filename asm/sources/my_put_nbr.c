/*
** my_put_nbr.c for my_put_nbr in /home/loens_g/rendu/Piscine_C_J07/lib/my
**
** Made by gregoire loens
** Login   <loens_g@epitech.net>
**
** Started on  Tue Oct  6 10:24:10 2015 gregoire loens
** Last update Tue Feb 16 09:30:36 2016 Grégoire Loens
*/

#include	<unistd.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

int     	my_put_nbr_base(int nbr, char *base)
{
  int        	m;
  int        	begin;
  int        	lbase;
  int        	nb;

  nb = 0;
  lbase = my_strlen(base);
  m = nbr % lbase;
  begin = (nbr - m) / lbase;
  if (begin != 0)
    my_put_nbr_base(begin, base);
  write(1, &base[m], 1);
  return (nb);
}
