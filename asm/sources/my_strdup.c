/*
** my_strdup.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar 21 17:10:44 2016 Grégoire Loens
** Last update Sun Mar 27 11:43:52 2016 
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"parser.h"

void		free_tab_cmd(char **cmd)
{
  int		cpt;

  cpt = 0;
  while (cpt < 34)
    {
      free(cmd[cpt]);
      cpt++;
    }
  free(cmd);
}

char		*my_strdup(const char *src)
{
  char		*dest;
  int		counter;

  counter = -1;
  if ((dest = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[++counter] != 0)
    dest[counter] = src[counter];
  dest[counter] = '\0';
  return (dest);
}
