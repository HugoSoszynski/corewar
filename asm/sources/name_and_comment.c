/*
** name_and_comment.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by Maxime Pillon
** Login   <pillon_m@epitech.net>
** 
** Started on  Fri Mar 25 02:21:33 2016 
** Last update Fri Mar 25 19:28:16 2016 
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"parser.h"
#include	"op.h"


#include	<stdio.h>


char		*check_one_name(t_cmd *cmd)
{
  t_cmd		*check;
  char		*name;
  int		cpt;

  check = cmd->head;
  cpt = 0;
  name = NULL;
  while (check != NULL)
    {
      if (check->type == TYPE_LINE_NAME)
	{
	  if (name == NULL)
	    name = check->line + 7;
	  else
	    return (NULL);
	}
      check = check->next;
    }
  while (name[cpt] != '"' && name[cpt] != '\0')
    cpt++;
  if (name[cpt] == '"')
    name[cpt] = '\0';
  return (name);
}

char		**comment_malloc(t_cmd *cmd)
{
  int		cpt;
  char		**comment;
  t_cmd		*check;

  cpt = 0;
  check = cmd;
  while (check != NULL)
    {
      if (check->type == TYPE_LINE_COMMENT)
	cpt++;
      check = check->next;
    }
  if ((comment = malloc(sizeof(char *) * (cpt + 2))) == NULL)
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
  return (0);
}

char		**where_comment(t_cmd *cmd)
{
  char		**comment;
  int		cpt;
  t_cmd		*check;

  cpt = 0;
  check = cmd->head;
  if ((comment = comment_malloc(check->head)) == NULL)
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
