/*
** label_and_prog_size.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu Mar 24 15:25:08 2016 
** Last update Thu Mar 24 17:41:08 2016 
*/

#include	"asm.h"
#include	"parser.h"
#include	"op.h"

int		strcmpend(char *str1, char *str2)
{
  int		cpt;

  cpt = 0;
  while (str1[cpt] && str2[cpt] && str1[cpt] == str2[cpt])
    ++cpt;
  if (!str2[cpt] && !str1[cpt])
    return (0);
  return (-1);
}

int		check_call_exist(t_cmd *cmd, t_pile *head)
{
  t_pile	*call;
  int		cpt;

  cpt = 0;
  call = cmd->call;
  while (call != NULL)
    {
      while (cmd->def != NULL)
	{
	  if (strcmpend(cmd->def->label_name, call->label_name) == 0)
	    cpt = 1;
	  cmd->def = cmd->def->next;
	}
      if (cpt == 1)
	return (-1);
      cmd->def = head;
      call = call->next;
    }
  cmd->def = head;
  return (0);
}

int		check_only_label(t_cmd *cmd)
{
  t_pile	*head;
  t_pile       	*check;

  head = cmd->def;
  if (check_call_exist(cmd, head) == -1)
    return (-1);
  if (cmd->def->next == NULL)
    return (0);
  while (cmd->def->next != NULL)
    {
      check = cmd->def;
      while (check->next != NULL)
	{
	  check = check->next;
	  if (strcmpend(cmd->def->label_name, check->label_name) != -1)
	    return (-1);
	}
      cmd->def = cmd->def->next;
    }
  cmd->def = head;
  return (0);
}

int		label_and_prog_size(t_cmd *cmd, int *prog_size)
{
  int		i;

  i = -1;
  *prog_size = 0;
  if (check_only_label(cmd) == -1)
    return (-1);
  while (cmd != NULL)
    {
      if (cmd->type == TYPE_LINE_CODE)
	*prog_size += cmd->dot_code_octet;
      if (cmd->type == TYPE_LINE_CMD || cmd->type TYPE_LINE_LABEL ||
	  cmd->type == TYPE_LINE_LABEL_CMD)
	while (++i < 3)
	  *prog_size += arg[i];
    }
}
