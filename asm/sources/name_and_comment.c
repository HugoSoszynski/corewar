/*
** name_and_comment.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu Mar 24 18:04:17 2016 
** Last update Thu Mar 24 18:32:59 2016 
*/

#include	"asm.h"
#include	"parser.h"
#include	"op.h"

char		*check_one_name(t_cmd *cmd)
{
  int		i;
  t_cmd		*check;
  char		*name;

  check = cmd;
  while (check != NULL)
    {
      if (check->type == TYPE_LINE_NAME)
	if (name == NULL)
	  name = check->line + 6;
	else
	  return (NULL);
      check = check->next;
    }
  return (name);
}

char		**comment_malloc(t_cmd *cmd)
{
  int		cpt;
  char		**comment;
  t_cmd		check;

  cpt = 0;
  check = cmd;
  while (check != NULL)
    {
      if (check->type == TYPE_LINE_COMMENT)
	cpt++;
      check = check->next;
    }
  if ((comment = malloc(sizeof(char *) * cpt + 1)) == NULL)
    return (NULL);
  return (comment);
}

int		check_size_comment(char **comment)
{
  int		cpt;
  int		size;

  size = 0;
  cpt = 0;
  while (comment[cpt] != NULL)
    {
      size += my_strlen(comment[cpt]);
      cpt++;
    }
  if (size > COMMENT_LENGTH)
    return (-1);
}

char		**where_comment(t_cmd *cmd)
{
  char		**comment;
  int		cpt;
  t_cmd		check;

  cpt = 0;
  check = cmd;
  if ((comment = comment_malloc(cmd)) == NULL)
    return (NULL);
  while (check != NULL)
    {
      if (check->type == TYPE_LINE_COMMENT)
	{
	  comment[cpt] = check->line+9;
	  cpt++;
	}
      check = check->next;
    }
  comment[cpt] = NULL;
  if (check_size_comment(comment) == -1)
    return (NULL);
  return (comment);
}
