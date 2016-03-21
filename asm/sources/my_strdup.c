/*
** my_strdup.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar 21 17:10:44 2016 Grégoire Loens
** Last update Mon Mar 21 17:19:54 2016 Grégoire Loens
*/

#include	<stdlib.h>

char		*my_strdup(const char *src)
{
  char		dest;
  int		counter;

  counter = -1;
  dest = malloc(sizeof(char) * my_strlen(src) + 1);
  while (src[++counter] != 0)
    dest[counter] = src[counter];
  return (dest);
}
