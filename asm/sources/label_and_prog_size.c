/*
** label_and_prog_size.c for  in /home/pillon_m/corewar/CPE_2015_corewar/asm/sources
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Thu Mar 24 15:25:08 2016 
** Last update Thu Mar 24 16:53:37 2016 
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

  call = cmd->call;
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
	if (check_only_label(cmd) == -1)
	  return (-1);
      }