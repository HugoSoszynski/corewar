/*
** get_next_line.c for  in /home/pillon_m/rendu/rendu/CPE_2015_getnextline
**
** Made by maxime pillon
** Login   <pillon_m@epitech.net>
**
** Started on  Mon Jan  4 16:30:44 2016 maxime pillon
** Last update Sun Feb 28 12:40:55 2016 
*/
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<unistd.h>
#include		<string.h>
#include		<stdlib.h>
#include		<fcntl.h>
#include		"get_next_line.h"

char			*my_realloc(char *str, int size)
{
  char			*str1;
  int			i;

  i = 0;
  str1 = malloc(sizeof(char) * (strlen(str) + size + 1));
  while (str[i] != '\0' && str[i] != '\n')
    {
      str1[i] = str[i];
      i++;
    }
  free(str);
  str1[i] = '\0';
  return (str1);
}

char			*cp_buffer(char *buf, char *str,
				   int i, int j)
{
  if (str[j] != '\0')
    while (str[j] != '\0' && str[j] != '\n')
      j++;
  while (buf[i] != '\0' && buf[i] != '\n')
    {
      str[j] = buf[i];
      i++;
      j++;
    }
  str[j] = '\0';
  str = my_realloc(str, READ_SIZE);
  return (str);
}

char 		*copy_buffer_ret(char *buf, char *str, int *ret)
{
  int			j;

  j = 0;
  (*ret)++;
  while (buf[(*ret)] != '\0' && buf[(*ret)] != '\n')
    {
      str[j] = buf[(*ret)];
      (*ret)++;
      j++;
    }
  str[j] = '\0';
  str = my_realloc(str, READ_SIZE);
  return (str);
}

char			*get_next_line(const int fd)
{
  static int		ret = 0;
  static char		buffer[READ_SIZE];
  char			*st;
  int			toto;

  if (((st = malloc(sizeof(char) * READ_SIZE + 1))) == NULL || (st[0] = '\0'))
    return (NULL);
  if (buffer[ret] == '\n' && buffer[ret + 1] != '\0')
    {
      st = copy_buffer_ret(buffer, st, &ret);
      if (buffer[ret] == '\n')
	return (st);
    }
  while ((toto = read(fd, buffer, READ_SIZE)) > 0 && (ret = -1))
    {
      buffer[toto] = '\0';
      st = cp_buffer(buffer, st, 0, 0);
      while (buffer[++ret] != '\0')
	if (buffer[ret] == '\n')
	  return (st);
    }
  if (st[0] != '\0')
    return (st);
  free(st);
  return (NULL);
}
