/*
** my_strlen.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 11:20:10 2016 Grégoire Loens
** Last update Tue Mar 22 11:07:45 2016 
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"asm.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int		my_isalpha_num(char c)
{
  if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (2);
  if (c == ' ' || c == '\t' || c == '\v' || c == '\b' || c == '\f' || c == '\r')
    return (-1);
  return (0);
}

int		my_strcmp(char *str, char *str1)
{
  int		i;

  i = -1;
  while (str[++i] != '\0' && str1[i] != '\0')
    {
      if (str[i] != str1[i])
	return (-1);
    }
  if (str1[i] != '\0')
    return (-1);
  else
    return (0);
}

int		my_ispace(char c)
{
  if (c == ' ' || c == '\t' || c == '\v')
    return (-1);
  return (0);
}

char		*my_isspace(char *input)
{
  int		cpt_input;
  int		cpt_output;
  char		*output;

  if ((output = malloc(sizeof(char) * my_strlen(input))) == NULL)
    return (NULL);
  cpt_input = 0;
  cpt_output = 0;
  while (input[cpt_input] != '\0')
    {
      if (my_ispace(input[cpt_input]) != -1)
	output[cpt_output] = input[cpt_input];
      else
	{
	  while (my_ispace(input[cpt_input]) == -1)
	    cpt_input++;
	  cpt_input -= 1;
	  output[cpt_output] = ' ';
	}
      cpt_output++;
      cpt_input++;
    }
  output[cpt_output] = '\0';
  return (output);
}
