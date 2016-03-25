/*
** my_endianess.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar  7 15:55:28 2016 Hugo SOSZYNSKI
** Last update Fri Mar 25 02:03:34 2016 
*/

/*
** Function wich check the endianess of the machine
** Returns 0 if Big Endian or 1 if Little Endian
*/

#include	"parser.h"
#include	"asm.h"

int		check_for_endianess()
{
  unsigned int	x;
  char		*c;

  x = 1;
  c = (char *)(&x);
  return ((int)(*c));
}

/*
** Called if machine is Little Endian
** Reverse the bytes of the variable
*/

void		my_reverse_bytes(void		*_value,
				 unsigned int 	size)
{
  unsigned int	i;
  char		tmp;
  char		*value;

  i = 0;
  value = _value;
  while (i < size / 2)
    {
      tmp = value[i];
      value[i] = value[size - i - 1];
      value[size - i - 1] = tmp;
      ++i;
    }
}
