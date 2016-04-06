/*
** name_and_comment.c for asm in /home/soszyn_h/rendu/CPE/CPE_2015_corewar/asm/sources
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sun Mar 27 23:18:36 2016 Hugo SOSZYNSKI
** Last update Mon Apr  4 19:33:57 2016 
*/

#include	<stddef.h>
#include	<stdlib.h>
#include	"asm.h"
#include	"parser.h"
#include	"op.h"

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
  if (name == NULL)
    return (NULL);
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

char		**where_comment(t_cmd *cmd, int cpt)
{
  char		**comment;
  int		cpt1;
  t_cmd		*check;

  cpt1 = -1;
  check = cmd->head;
  if ((comment = comment_malloc(check->head)) == NULL)
    return (NULL);
  while (check != NULL)
    {
      if (check->type == TYPE_LINE_COMMENT)
	{
	  comment[cpt] = my_strdup(check->line+10);
	  while (comment[cpt][++cpt1] != '"');
	  comment[cpt][cpt1] = '\0';
	  cpt1 = -1;
	  cpt++;
	}
      check = check->next;
    }
  comment[cpt] = NULL;
  if (check_size_comment(comment) == -1)
    return (NULL);
  return (comment);
}
