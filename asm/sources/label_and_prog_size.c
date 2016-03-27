/*
** label_and_prog_size.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu Mar 24 15:25:08 2016 
** Last update Sun Mar 27 19:45:08 2016 
*/

#include	<stddef.h>
#include	"asm.h"
#include	"parser.h"
#include	"op.h"

#include	<unistd.h>
#include	<stdio.h>


int		strcmpend(char *str1, char *str2)
{
  int		cpt;

  cpt = 0;
  if (str1 == NULL || str2 == NULL)
    return (-1);
  while (str1[cpt] && str2[cpt] && str1[cpt] == str2[cpt])
    ++cpt;
  if (!str2[cpt] && !str1[cpt])
    return (0);
  return (-1);
}

int		check_call_exist(t_cmd *cmd)
{
  t_pile	*call;
  t_pile	*def;
  int		cpt;

  cpt = 0;
  call = cmd->call;
  def = cmd->def;
  while (call != NULL && call->label_name != NULL)
    {
      while (def != NULL && def->label_name != NULL && cpt != 1)
	{
	  if (strcmpend(def->label_name, call->label_name) == 0)
	    cpt = 1;
	  def = def->next;
	}
      if (cpt != 1)
	  return (-1);
      def = cmd->def;
      call = call->next;
      cpt = 0;
    }
  cmd = cmd->head;
  return (0);
}

t_cmd		*check_only_label(t_cmd *cmd)
{
  t_pile       	*check;
  t_pile	*start;

  start = cmd->def;
  if (check_call_exist(cmd) == -1)
    return (NULL);
  cmd = cmd->head;
  if (cmd->def->next == NULL)
    return (cmd);
  while (cmd->def->next != NULL)
    {
      check = cmd->def;
      while (check->next != NULL)
	{
	  check = check->next;
	  if (strcmpend(cmd->def->label_name, check->label_name) != -1)
	    return (NULL);
	}
      cmd->def = cmd->def->next;
    }
  cmd = cmd->head;
  cmd->def = start;
  return (cmd);
}

int		label_and_prog_size(t_cmd *cmd, int *prog_size)
{
  int		i;
  t_cmd		*head;

  head = cmd;
  cmd = cmd->head;
  *prog_size = 0;
  if ((cmd = check_only_label(cmd)) == NULL)
    return (-1);
  cmd = cmd->head;
  while (cmd != NULL)
    {
      i = -1;
      if (cmd->type == TYPE_LINE_CODE)
	*prog_size += cmd->dot_code_octet;
      else if (cmd->type == TYPE_LINE_CMD || cmd->type == TYPE_LINE_LABEL ||
	       cmd->type == TYPE_LINE_LABEL_CMD)
	while (++i < 3)
	  if (cmd->type_arg[i] < 10)
	    *prog_size += cmd->type_arg[i];
	  else
	    *prog_size += cmd->type_arg[i] - 10;
      cmd = cmd->next;
    }
  cmd = head;
  return (0);
}
