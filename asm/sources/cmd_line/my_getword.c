/*
** my_getword.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources/cmd_line
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 15:18:11 2016 
** Last update Tue Mar 22 14:34:36 2016 
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"parser.h"
#include	"asm.h"

int		start_word(char *line, int word_nbr)
{
  int		cpt;
  int		i;

  cpt = 1;
  i = 0;
  while (cpt != word_nbr && line[i] != '\0')
    {
      if (line[i] == ' ')
	cpt++;
      i++;
    }
  if (line[i] == '\0')
    return (-1);
  return (i);
}

char		*my_getword(char *line, int word_nbr)
{
  int		cpt;
  int		cpt1;
  char		*word;

  cpt1 = 0;
  if ((cpt = start_word(line, word_nbr)) == -1)
    return (NULL);
  if ((word = malloc(sizeof(char) * my_strlen(line + cpt))) == NULL)
    return (NULL);
  while (line[cpt] != ' ' && line[cpt] != '\0')
    {
      word[cpt1] = line[cpt];
      cpt1++;
      cpt++;
    }
  return (word);
}
