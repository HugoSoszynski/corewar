/*
** my_endianess.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources/
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar  7 15:55:28 2016 Hugo SOSZYNSKI
** Last update Sun Mar 27 21:03:18 2016 Hugo SOSZYNSKI
*/

int		check_for_endianess()
{
  unsigned int	x;
  char		*c;

  x = 1;
  c = (char *)(&x);
  return ((int)(*c));
}

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
