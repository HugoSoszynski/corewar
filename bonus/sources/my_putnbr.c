/*
** my_putnbr.c for bite in /home/corsin_a/Travail/CPE/CPE_2015_corewar/corewar/sources/
**
** Made by corsin_a
** Login   <sylvain.corsini@epitech.eu>
**
** Started on  Mon Mar 21 21:26:22 2016 corsin_a
** Last update Mon Mar 21 21:26:25 2016 corsin_a
*/

#include	<unistd.h>

void		my_putnbr(int nb)
{
  unsigned int	div;
  char	      	c;

  div = 1;
  while ((nb / div) >= 10)
    div *= 10;
  while (div >= 1)
    {
      c = (nb / div) % 10 + '0';
      write(1, &c, 1);
      div /= 10;
    }
}
