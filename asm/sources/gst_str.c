/*
** my_strlen.c for corewar in /home/loens_g/Rendu/CPE_2015_corewar/asm/sources/
**
** Made by Grégoire Loens
** Login   <loens_g@epitech.net>
**
** Started on  Mon Mar  7 11:20:10 2016 Grégoire Loens
** Last update Sun Mar 27 23:32:19 2016 Hugo SOSZYNSKI
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"asm.h"

int		my_isalpha_num(char c)
{
  if ((c >= '0' && c <= '9') ||
      (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (2);
  if (c == ' ' || c == '\t' ||
      c == '\v' || c == '\b' || c == '\f' || c == '\r')
    return (-1);
  return (0);
}

int		my_ispace(char c)
{
  if (c == ' ' || c == '\t' || c == '\v')
    return (-1);
  return (0);
}

char		*check_only_space(char *output, char *input, int cpt_output)
{
  int		cpt;
  int		var;

  var = 0;
  cpt = 0;
  output[cpt_output] = '\0';
  while (output[cpt] != '\0')
    {
      if (my_ispace(output[cpt]) != -1)
	var++;
      cpt++;
    }
  if (var == 0)
    output[0] = '\0';
  free(input);
  input = NULL;
  return (output);
}

char		*my_isspace(char *input, int cpt_input, int cpt_output)
{
  char		*output;

  if ((output = malloc(sizeof(char) * my_strlen(input) + 1)) == NULL)
    return (NULL);
  while (my_ispace(input[cpt_input]) == -1 && input[cpt_input] != '\0')
    cpt_input++;
  while (input[cpt_input] != '\0')
    {
      if (my_ispace(input[cpt_input]) == 0 && input[cpt_input] != COMMENT_CHAR)
	output[cpt_output] = input[cpt_input];
      else if (input[cpt_input] == COMMENT_CHAR || input[cpt_input] == ';')
	return (check_only_space(output, input, cpt_output));
      else
	{
	  output[cpt_output] = ' ';
	  while (input[cpt_input] != '\0' && my_ispace(input[cpt_input]) == -1)
	    cpt_input++;
	  cpt_input -= 1;
	}
      cpt_input++;
      cpt_output++;
    }
  return (check_only_space(output, input, cpt_output));
}
