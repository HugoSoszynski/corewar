/*
** my_strlen.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 11:20:10 2016 Grégoire Loens
** Last update Mon Mar  7 11:30:14 2016 Grégoire Loens
*/

int		my_strlen(char *str, int i)
{
  while ((*str) != '\0' && ++i == i && ++str == str);
  return (i + 1);
}
